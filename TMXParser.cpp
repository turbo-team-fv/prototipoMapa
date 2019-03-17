
#include "TMXParser.h"

#include <cstdlib>
#include <iostream>
#include <sstream>

namespace TMX {

  Parser::Parser( const char* filename )
  {
    load( filename );
  }

  Parser::Parser()
  {
  }

  Parser::~Parser()
  {
  }

  bool Parser::load( const char* filename )
  {
    std::string version = VERSION;
    rapidxml::xml_node<>* root_node;
    rapidxml::xml_document<> doc;
    rapidxml::file<> file( filename );
    doc.parse<0>( file.data() );
    //get root nodes
    root_node = doc.first_node( "map" );

    //load map element
    if( root_node->first_attribute( "version" )->value() != version ) {
      std::cout << "ERROR: Map version mismatch. Required version: " << VERSION << "." << std::endl;
      std::cout << "LO QUE SE HA ENCONTRAO: " << root_node->first_attribute( "version" )->value() << "." << std::endl;
      return false;
    }

    mapInfo.version = root_node->first_attribute( "version" )->value();
    std::cout << "Version: " << mapInfo.version << std::endl;
    mapInfo.orientation = root_node->first_attribute( "orientation" )->value();
    std::cout << "Orientation: " << mapInfo.orientation << std::endl;
    mapInfo.width = std::atoi( root_node->first_attribute( "width" )->value() );
    std::cout << "Width: " << mapInfo.width << std::endl;
    mapInfo.height = std::atoi( root_node->first_attribute( "height" )->value() );
    std::cout << "Height: " << mapInfo.height << std::endl;
    mapInfo.tileWidth = std::atoi( root_node->first_attribute( "tilewidth" )->value() );
    std::cout << "Tile Width: " << mapInfo.tileWidth << std::endl;
    mapInfo.tileHeight = std::atoi( root_node->first_attribute( "tileheight" )->value() );
    std::cout << "Tile Height: " << mapInfo.tileHeight << std::endl;

    if( root_node->first_attribute( "backgroundcolor" )->value() != 0 )
    {
      mapInfo.backgroundColor = root_node->first_attribute( "backgroundcolor" )->value();
      std::cout << "Background Color: " << mapInfo.backgroundColor << std::endl;
    }

    for (rapidxml::xml_node<>* tileset_node = root_node->first_node("tileset"); tileset_node; tileset_node = tileset_node->next_sibling("tileset") ) /// para cada uno de los tileset en el archivo
    {
        Tileset tmpTileset;
        tmpTileset.firstGID = std::atoi(tileset_node->first_attribute("firstgid")->value());
        tmpTileset.source = tileset_node->first_node("image")->first_attribute("source")->value();
        std::cout << "Texture source(s) path: " << tmpTileset.source << std::endl;
        tilesetList.push_back(tmpTileset);
    }

    for (rapidxml::xml_node<>* layer_node = root_node->first_node("layer"); layer_node; layer_node = layer_node->next_sibling("layer"))
    {
        TileLayer layer;

        layer.name = layer_node->first_attribute("name")->value();
        layer.id = std::atoi(layer_node->first_attribute("id")->value());
        layer.width = std::atoi(layer_node->first_attribute("width")->value());
        layer.height = std::atoi(layer_node->first_attribute("height")->value());

        std::cout << "Layer " << layer.id << " correctly loaded. Size: " << layer.width << "x" << layer.height << std::endl;

        std::vector<Object> objectRow;
        int flag = 0;
        for (rapidxml::xml_node<>* tile_node = layer_node->first_node("tile"); tile_node; tile_node = tile_node->next_sibling("tile"))
        {
            if(flag < 10)
            {
                Object tmpObject;
                tmpObject.gid = std::atoi(tile_node->first_attribute("gid")->value());
                objectRow.push_back(tmpObject);
                flag++;
            }
            else
                // vaciar el vector
        }
    }


    return true;
  }
}
