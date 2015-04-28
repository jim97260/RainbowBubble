/*
 * CharacterSystem.h
 *
 *  Created on: 2015�~4��26��
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
	// ���o���⪺����
	LayerColor* myCharacter();
	Sprite*  myCharacter();
*/
	// ���o / �]�w ���⪺��m
	void setPosition(Point);
	Point getPosition();

	// ���o / �]�w ���⪺��V
	void setOrien(float);
	float getOrien();
	// ���o / �]�w ���⪺�t��
	void setSpeed(float);
	float getSpeed();
private:
	LayerColor*			_characterLayer;
	Label* 					_characterLabel;
	DrawNode*			_characterNode;
	//Sprite*					_character;
	int 						_characterType;			// ������� 0:���a 1:�ĤH 2:��ê��
	float					_characterOrien;			// ���⪺���ʤ�V (0~360)
	float 					_characterSpeed;		// ���⪺���ʳt��*/
	//vector<Bubble> _characterBubble;		// ����o�g���w�w
};

#endif /* SYSTEM_CHARACTERSYSTEM_H_ */
