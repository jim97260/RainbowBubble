/*
 * StageSystem.h
 *
 *  Created on: 2015年4月26日
 *      Author: Jinyu
 */

#ifndef SYSTEM_STAGESYSTEM_H_
#define SYSTEM_STAGESYSTEM_H_

#include "AllIncludeHeader.h"
/*
class Stage {
public:
	enum LEN {LEN_LONG = 180, LEN_MID = 120, LEN_SHORT = 60, LEN_CUSTOM = -1};
	enum SPD {SPD_FAST = 3, SPD_MID = 2, SPD_SLOW = 1, SPD_CUSTOM = -1};
	enum SEQ {SEQ_MUCH = 15, SEQ_MID = 10, SEQ_FEW = 5, SEQ_CUSTOM = -1};
	enum COF {COF_ENEMY = 3, COF_OBSCATLE = 2, COF_ITEM = 1};
	// 創造一個預設關卡
	Stage();
	// 創造一個關卡(ID, 長度, 速度, 玩家角色, 敵方角色, 障礙物, 道具)
	Stage(int, float, float, Character, vector<Character>, vector<Character>, vector<Item>);

private:
	int								_stageID;					// 紀錄關卡ID
	float 							_stageLength;			// 紀錄關卡長度
	float 							_stageSpeed;			// 紀錄關卡捲動速度
	float							_stageNow;				// 紀錄關卡現在進度
	int								_stageEnemyCnt;	// 紀錄敵方角色數量
	int 								_stageObscatleCnt;// 紀錄障礙物數量
	int								_stageItemCnt;		// 紀錄道具數量

	Character 					_stagePlayer;			// 紀錄玩家角色
	vector<Character> 	_stageEnmeys[];		// 記錄所有敵方角色
	vector<Character> 	_stageObscatles[];	// 記錄所有障礙物
	vector<Item> 			_stageItems[];			// 記錄所有道具
};
*/
#endif /* SYSTEM_STAGESYSTEM_H_ */
