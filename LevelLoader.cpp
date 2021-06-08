#include "LevelLoader.h"

LevelLoader& LevelLoader::get()
{
	static LevelLoader instance;
	return instance;
}

void LevelLoader::loadData(int &id)
{
	return get().IloadData(id);
}

void LevelLoader::IloadData(int& id)
{
	/*std::cout << "LoadingData" << std::endl;

	int aux = 4;
	*/

	/*json test = R"(
				{
				"happy": true,
				"pi" : 3.141,
				"aux" : {
					"1" : {
						"1.1":33,
						"1.2":55
						},
					"2" : 44
					}
				}
				)"_json;

	std::cout << test.dump(2) << std::endl;*/

	std::stringstream path;
	path << "./LevelInfo/" << id << ".json";

	std::ifstream file(path.str());

	json test;

	file >> test;

	std::stringstream tile;

	for (int i = 1; i <= test["Tiles"].size(); i++) {
		tile << "tile" << i;
		json auxJson = test["Tiles"][tile.str()];

		Rectangle auxRec = { auxJson["x"], auxJson["y"], auxJson["Width"], auxJson["Height"] };
		Tile auxTile = { auxRec, 1, LIGHTGRAY };

		this->tiles.push_back(auxTile);
		
		tile.str(std::string());
	}

	file.close();


}

LevelLoader::LevelLoader()
{
	tiles =  std::vector<Tile>();
}
