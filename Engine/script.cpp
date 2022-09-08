#include <iostream>
#include <list>
#include <algorithm>
#include <map>
#include <memory>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "block.cpp" 
using namespace sf;

class Script {
public:

	Script(){}

	void startAddScenes() {
		persons = new std::map<std::string, Person*>;

		// добавляем персонажей
		addPerson("Stepan", 9, Color::Yellow);
		addPerson("Julia", 3, Color::Green);
		addPerson("Karina", 3, Color::Cyan);
		

		// вступительные сцены
		addScene("start1");
		getScene("start1").addPhrase(getPerson("Stepan"), L"Черт... Я опять проспал, надо бежать.", 2);

		addScene("start2");
		getScene("start2").addPhrase(getPerson("Stepan"), L"->", 0);
		
		addScene("start3");
		getScene("start3").addPhrase(getPerson("Julia"), L"-Привет.Опять опаздываешь?", 1);
		getScene("start3").addPhrase(getPerson("Stepan"), L"Ха-ха...", 0);
		getScene("start3").addPhrase(getPerson("Julia"), L"Ладно, садись. Ты занят после школы?", 0);
		getScene("start3").addPhrase(getPerson("Julia"), L"s", 1);
		getScene("start3").addPhrase(getPerson("Karina"), L"Привееееетик, о чем говорите?", 1);
		getScene("start3").addPhrase(getPerson("Julia"), L"Не важно, у нас тут свои приколы.", 2);
		getScene("start3").addPhrase(getPerson("Karina"), L"Юля, ты такая агрессивная... Степан, ты же хорош в математике, да?", 1);
		getScene("start3").addPhrase(getPerson("Karina"), L"Позанимаешься со мной после школы? Экзамены на носу.", 0);
		getScene("start3").addPhrase(getPerson("Julia"), L"Карина, мы со Степаном уже договорились пойти сегодня в парк. Скажи ей, Степан.", 2);
		getScene("start3").addPhrase(getPerson("Karina"), L"Это правда?", 2);
		getScene("start3").addPhrase(getPerson("Stepan"), L"||", 0);

		// добавляем сцены в блок
		blockContainer.push_back(new Block);
		blockContainer[0]->addScene(&getScene("start1"));
		blockContainer[0]->addScene(&getScene("start2"));
		blockContainer[0]->addScene(&getScene("start3"));
		blockContainer[0]->addChoise(L"Помочь с матешей", L"Пойти в парк");

		// выбор 1
		addScene("choise1_1i1");
		getScene("choise1_1i1").addPhrase(getPerson("Stepan"), L"Хорошо, Карина, я помогу тебе с подготовкой к экзамену.", 0);

		addScene("choise1_1i2");
		getScene("choise1_1i2").addPhrase(getPerson("Stepan"), L"->", 0);
		getScene("choise1_1i2").addPhrase(getPerson("Karina"), L"Так...это сюда...и так...", 0);
		getScene("choise1_1i2").addPhrase(getPerson("Stepan"), L"Готово!", 1);
		getScene("choise1_1i2").addPhrase(getPerson("Stepan"), L"", 0);
		getScene("choise1_1i2").addPhrase(getPerson("Stepan"), L"Молодец, Карина, у тебя начинает получаться!", 1);
		getScene("choise1_1i2").addPhrase(getPerson("Karina"), L"s", 1);

		addScene("choise1_1i3");
		getScene("choise1_1i3").addPhrase(getPerson("Stepan"), L"->", 0);
		getScene("choise1_1i3").addPhrase(getPerson("Karina"), L"Ой, уже так поздно, мне пора идти.", 0);
		getScene("choise1_1i3").addPhrase(getPerson("Stepan"), L"Может останешься?", 0);
		getScene("choise1_1i3").addPhrase(getPerson("Karina"), L"Не стоит.", 0);
		getScene("choise1_1i3").addPhrase(getPerson("Stepan"), L"Но уже так темно, может я хотя бы тебя провожу?", 0);
		getScene("choise1_1i3").addPhrase(getPerson("Karina"), L"Я была бы только рада, но тебе же вроде нравится Юля...", 0);
		getScene("choise1_1i3").addPhrase(getPerson("Stepan"), L"Но почему тогда я сейчас провожу время с тобой, а не с ней?)", 1);
		getScene("choise1_1i3").addPhrase(getPerson("Karina"), L"Не знаю, может потому что ты очень добрый и просто захотел мне помочь...", 2);
		getScene("choise1_1i3").addPhrase(getPerson("Stepan"), L"Нет, ты мне очень нравишься, поэтому я и общался с Юлей.", 0);
		getScene("choise1_1i3").addPhrase(getPerson("Karina"), L"Ты мне тоже очень нравишься, но я очень боялась тебе признаться, я так рада...", 1);

		addScene("choise1_1i4");
		getScene("choise1_1i4").addPhrase(getPerson("Stepan"), L"", 0);
		getScene("choise1_1i4").addPhrase(getPerson("Stepan"), L"end", 0);

		blockContainer.push_back(new Block);
		blockContainer[1]->addScene(&getScene("choise1_1i1"));
		blockContainer[1]->addScene(&getScene("choise1_1i2"));
		blockContainer[1]->addScene(&getScene("choise1_1i3"));
		blockContainer[1]->addScene(&getScene("choise1_1i4"));


		// 2 выбор
		addScene("choise1_2i1");
		getScene("choise1_2i1").addPhrase(getPerson("Stepan"), L"Это правда, мы с Юлей уже договорились пойти гулять.", 0);
		getScene("choise1_2i1").addPhrase(getPerson("Karina"), L"Но экзамен уже завтра!", 2);
		getScene("choise1_2i1").addPhrase(getPerson("Stepan"), L"Извини.", 0);

		addScene("choise1_2i2");
		getScene("choise1_2i2").addPhrase(getPerson("Stepan"), L"->", 0);
		getScene("choise1_2i2").addPhrase(getPerson("Julia"), L"Степан, тут так красиво, с тобой тут всё выглядит и чувствуется по-иному...", 1);
		getScene("choise1_2i2").addPhrase(getPerson("Stepan"), L"Да, я понимаю, я чувствую то же самое...", 1);
		
		addScene("choise1_2i3");
		getScene("choise1_2i3").addPhrase(getPerson("Stepan"), L"->", 0);
		getScene("choise1_2i3").addPhrase(getPerson("Julia"), L"Ух ты! А что это там?", 1);
		getScene("choise1_2i3").addPhrase(getPerson("Stepan"), L"Где?", 0);
		getScene("choise1_2i3").addPhrase(getPerson("Julia"), L"", 0);
		getScene("choise1_2i3").addPhrase(getPerson("Stepan"), L"Постой!", 0);
		getScene("choise1_2i3").addPhrase(getPerson("Julia"), L"Луна сегодня красивая, правда?", 1);
		getScene("choise1_2i3").addPhrase(getPerson("Stepan"), L"->", 0);
		getScene("choise1_2i3").addPhrase(getPerson("Stepan"), L"Правда...", 1);
		getScene("choise1_2i3").addPhrase(getPerson("Stepan"), L"Уже довольно поздно, может пора идти по домам?", 0);
		getScene("choise1_2i3").addPhrase(getPerson("Julia"), L"Нееет!", 2);
		getScene("choise1_2i3").addPhrase(getPerson("Julia"), L"Давай посидим еще немного.", 0);
		getScene("choise1_2i3").addPhrase(getPerson("Julia"), L"Мне тут так нравится.", 0);
		getScene("choise1_2i3").addPhrase(getPerson("Stepan"), L"Ладно...", 0);

		addScene("choise1_2i4");
		getScene("choise1_2i4").addPhrase(getPerson("Stepan"), L"", 0);
		getScene("choise1_2i4").addPhrase(getPerson("Stepan"), L"end", 0);

		blockContainer.push_back(new Block);
		blockContainer[2]->addScene(&getScene("choise1_2i1"));
		blockContainer[2]->addScene(&getScene("choise1_2i2"));
		blockContainer[2]->addScene(&getScene("choise1_2i3"));
		blockContainer[2]->addScene(&getScene("choise1_2i4"));

	}

	~Script() {}

	void addScene(std::string key) {
		Scene* scene = new Scene((*textureContainer)["/galery/" + key + ".jpg"]);
		sceneContainer->insert(std::make_pair("/galery/" + key + ".jpg", scene));
	}

	Scene& getScene(std::string key) {
		return *(*sceneContainer)["/galery/" + key + ".jpg"]; // key
	}

	Block& getBlock(int key) {
		return *blockContainer[key]; // key
	}

	void addPerson(std::string name, int spritesNum, Color color = Color::White) {
		Person* person = new Person(name, spritesNum, color);
		persons->insert(std::make_pair(name, person));
	}

	Person* getPerson(std::string key) {
		return (*persons)[key];
	}


	void setTextureContainer(std::map<std::string, Texture*>* textureContainer) {
		this->textureContainer = textureContainer;
	}

	void setSceneContainer(std::map<std::string, Scene*>* sceneContainer) {
		this->sceneContainer = sceneContainer;
	}

	void setFont(Font menuFont, Font textFont) {
		this->menuFont = menuFont;
		this->textFont = textFont;
	}

	void setTextSize(int menuButtonSize, int textSize) {
		this->menuTextSize = menuButtonSize;
		this->textSize = textSize;
	}



private:
	std::map<std::string, Texture*>* textureContainer = nullptr;

	std::map<std::string, Scene*>* sceneContainer = nullptr;
	std::vector<std::string> keys;
	
	std::map<std::string, Person*>* persons = nullptr;

	std::vector<Block*> blockContainer;

	Font menuFont;
	int menuTextSize;

	Font textFont;
	int textSize;
};