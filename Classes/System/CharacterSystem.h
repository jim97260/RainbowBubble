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
	enum CHAR_TYPE {PLAYER = 0, ENEMY, ONSTACLE};
	enum SHOW_TYPE {SHOW_LAYER = 10, SHOW_SPRITE};
	enum ORIEN_TYPE {ORIEN_NORMAL = 20, ORIEN_VECTOR};
	enum DIM_TYPE {ALL_DIM = 30, ONLY_X, ONLY_Y, NO_DIM};
	Character();
	Character(Layer*);
	Character(Layer*, int, Point, float, float, float, float, float, Sprite*);

	void move(float);
/*
	void attack();
	void dead();
*//*
	// 取得角色的實體
	LayerColor* myCharacter();
	Sprite*  myCharacter();
*/
	// 顯示角色速度的實體化線條
	void showLine();

	// 取得 / 設定 角色的位置
	void setPosition(Point);
	Point getPosition();

	// 取得 / 設定 角色的方向
	void setOrien(Point, int);
	void setOrien(Point);
	float getOrien();

	// 取得 / 設定 角色的速度
	void setSpeed(float);
	float getSpeed();

	// 加速 / 減速 角色
	void upSpeed(float);
	void downSpeed(float);
private:
	LayerColor*			_cLayer;			// 顯示角色位置區塊用
	Label* 					_cLabel;			// 顯示角色移動方向角度用
	DrawNode*			_cNode;			// 顯示角色速度線用
	Sprite*					_cSprite;			// 顯示角色圖像用
	int 						_cType;			// 角色種類 0:玩家 1:敵人 2:障礙物
	int 						_cOrienType;	// 角色的方向計算方式 0: 不計算 1: 用向量加法
	int						_cDimType;		// 角色可移動的維度類型 0: X,Y 維度皆可 1: 只有X維度 2: 只有Y維度 3:無法移動
	float					_cOrien;			// 角色的移動方向 (0~360)
	float 					_cSpeed;			// 角色的移動速度
	float					_cMaxSpeed;	// 角色的最高速度
	float					_cAccSpeed;	// 角色的加速度
	float					_cDecSpeed;	// 角色的減速度
	float					_cTunSpeed;	// 角色的轉彎速度 (只在向量加法模式有用)
	//vector<Bubble> _cBubble;		// 角色發射的泡泡
};

#endif /* SYSTEM_CHARACTERSYSTEM_H_ */
