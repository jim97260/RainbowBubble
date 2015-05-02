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
	/**	參數
	 *     1 2	位為角色類型參數
	 *     3		位為顯示類型參數
	 *     4		位為轉向類型參數
	 *     5 6	位為維度限制參數
	 * 		                                                             位數:	6 5 4 3 2 1	 */
	enum CHAR_TYPE {	CHAR = 3,
										CHAR_EMPTY = 0,			//             0 0
										CHAR_PLAYER = 1,			//             0 1
										CHAR_ENEMY = 2,			//             1 0
										CHAR_ONSTACLE = 3};	//             1 1
	enum SHOW_TYPE {	SHOW = 4,
										SHOW_LAYER = 0,			//          0
										SHOW_SPRITE = 4};		//          1
	enum ORIEN_TYPE {	ORIEN = 8,
										ORIEN_NORMAL = 0,		//       0
										ORIEN_VECTOR = 8};		//       1
	enum DIM_TYPE {		DIM = 48,
										DIM_ALL = 48,				// 1 1
										DIM_ONLY_X = 32,			// 1 0
										DIM_ONLY_Y = 16,			// 0 1
										DIM_NULL = 0};				// 0 0
	enum SPRITE_OIREN {	SPORI_DOWN = 0,
											SPORI_LEFT = 1,
											SPORI_RIGHT = 2,
											SPORI_UP = 3,
	};

	Character();
	Character(Layer*);
	Character(Layer*, int, Point, float, float, float, float, float, Sprite*);

	void move(float);
	void stop();
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
	int 						_cPara;				// 角色的各項設定參數
	float					_cOrien;			// 角色的移動方向 (0~360)
	float 					_cSpeed;			// 角色的移動速度
	float					_cMaxSpeed;	// 角色的最高速度
	float					_cAccSpeed;	// 角色的加速度 (簡單的說就是幾分之一秒加至最高速)
	float					_cDecSpeed;	// 角色的減速度 (簡單的說就是幾分之一秒減至最低速)
	float					_cTunSpeed;	// 角色的轉彎速度 (只在向量加法模式有用) (0 ~ 100)

	int _cSpriteX;
	float _cSpriteNowX;
	int _cSpriteY;
	float _cSpriteNowY;
	vector<int> _cSpriteOri;
	float _cSpriteWidth;
	float _cSpriteHeight;
	//vector<Bubble> _cBubble;		// 角色發射的泡泡
};

#endif /* SYSTEM_CHARACTERSYSTEM_H_ */
