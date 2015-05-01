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
	// ���o���⪺����
	LayerColor* myCharacter();
	Sprite*  myCharacter();
*/
	// ��ܨ���t�ת�����ƽu��
	void showLine();

	// ���o / �]�w ���⪺��m
	void setPosition(Point);
	Point getPosition();

	// ���o / �]�w ���⪺��V
	void setOrien(Point, int);
	void setOrien(Point);
	float getOrien();

	// ���o / �]�w ���⪺�t��
	void setSpeed(float);
	float getSpeed();

	// �[�t / ��t ����
	void upSpeed(float);
	void downSpeed(float);
private:
	LayerColor*			_cLayer;			// ��ܨ����m�϶���
	Label* 					_cLabel;			// ��ܨ��Ⲿ�ʤ�V���ץ�
	DrawNode*			_cNode;			// ��ܨ���t�׽u��
	Sprite*					_cSprite;			// ��ܨ���Ϲ���
	int 						_cType;			// ������� 0:���a 1:�ĤH 2:��ê��
	int 						_cOrienType;	// ���⪺��V�p��覡 0: ���p�� 1: �ΦV�q�[�k
	int						_cDimType;		// ����i���ʪ��������� 0: X,Y ���׬ҥi 1: �u��X���� 2: �u��Y���� 3:�L�k����
	float					_cOrien;			// ���⪺���ʤ�V (0~360)
	float 					_cSpeed;			// ���⪺���ʳt��
	float					_cMaxSpeed;	// ���⪺�̰��t��
	float					_cAccSpeed;	// ���⪺�[�t��
	float					_cDecSpeed;	// ���⪺��t��
	float					_cTunSpeed;	// ���⪺���s�t�� (�u�b�V�q�[�k�Ҧ�����)
	//vector<Bubble> _cBubble;		// ����o�g���w�w
};

#endif /* SYSTEM_CHARACTERSYSTEM_H_ */
