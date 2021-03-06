#ifndef TMXPARSER_H
#define TMXPARSER_H

//#include <TSXParser.h>
#include "rapidxml/rapidxml.hpp"
#include "rapidxml/rapidxml_utils.hpp"

#include <string>
#include <vector>
#include <utility>
#include <map>

#define VERSION "1.2"

namespace TMX
{

  class Parser
  {
    public:
      Parser( const char* filename );
      Parser();
      virtual ~Parser();

      bool load( const char* filename );

      struct Map {
        std::string version;
        std::string orientation;
        unsigned int width;
        unsigned int height;
        unsigned int tileWidth;
        unsigned int tileHeight;
        std::string backgroundColor;
        std::map<std::string, std::string> property;
      };

      struct Tileset {
        unsigned int firstGID;
        unsigned int tileHeight;
        unsigned int tileWidth;
        unsigned int spacing;
        unsigned int columns;
        unsigned int tileCount;
        std::string source;
      };

      struct Data {
        std::string encoding;
        std::string compression;
        std::string contents;
      };

      struct TileLayer {
        int id;
        std::string name;
        bool visible;
        float opacity;
        Data data;
        unsigned int width;
        unsigned int height;
        std::map<std::string, std::string> property;
      };

      struct Object {
        std::string name;
        std::string type;
        int x;
        int y;
        unsigned int width;
        unsigned int height;
        unsigned int gid;
        bool visible;
        std::map<std::string, std::string> property;
      };

      struct ObjectGroup {
        std::string color;
        std::string name;
        float opacity;
        bool visible;
        std::vector<std::vector<Object>> objects;
        std::map<std::string, std::string> property;
      };

      struct Image {
        std::string source;
        std::string transparencyColor;
      };

      struct ImageLayer {
        std::string name;
        float opacity;
        bool visible;
        std::map<std::string, std::string> property;
        Image image;
      };

      Map mapInfo;
      std::vector<Tileset> tilesetList;
      std::map<std::string, TileLayer> tileLayer;
      std::map<std::string, ObjectGroup> objectGroup;
      std::map<std::string, ImageLayer> imageLayer;
    protected:
    private:
  };

}
#endif // TMXPARSER_H
