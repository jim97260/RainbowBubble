/*
 * CharacterSystem.h
 *
 *  Created on: 2015年4月26日
 *      Author: Jinyu
 */

#ifndef SYSTEM_CHARACTERSYSTEM_H_
#define SYSTEM_CHARACTERSYSTEM_H_

#include "AllIncludeHeader.h"

class Character {
public :
	enum TYPE{PLAYER = 0, ENEMY, ONSTACLE};
	Character();
	Character(Layer*);
	//Character(int, Point, float, float);
	void showLine();
/*
	void attack();
	void move();
	void dead();
*//*
	// 取得角色的實體
	LayerColor* myCharacter();
	Sprite*  myCharacter();
*/
	// 取得 / 設定 角色的位置
	void setPosition(Point);
	Point getPosition();

	// 取得 / 設定 角色的方向
	void setOrien(float);
	float getOrien();
	// 取得 / 設定 角色的速度
	void setSpeed(float);
	float getSpeed();
private:
	LayerColor*			_characterLayer;
	Label* 					_characterLabel;
	DrawNode*			_characterNode;
	//Sprite*					_character;
	int 						_characterType;			// 角色種類 0:玩家 1:敵人 2:障礙物
	float					_characterOrien;			// 角色的移動方向 (0~360)
	float 					_characterSpeed;		// 角色的移動速度*/
	//vector<Bubble> _characterBubble;		// 角色發射的泡泡
};

#endif /* SYSTEM_CHARACTERSYSTEM_H_ */
