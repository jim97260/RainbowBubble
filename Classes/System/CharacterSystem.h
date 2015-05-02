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
	/**	�Ѽ�
	 *     1 2	�쬰���������Ѽ�
	 *     3		�쬰��������Ѽ�
	 *     4		�쬰��V�����Ѽ�
	 *     5 6	�쬰���׭���Ѽ�
	 * 		                                                             ���:	6 5 4 3 2 1	 */
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
	int 						_cPara;				// ���⪺�U���]�w�Ѽ�
	float					_cOrien;			// ���⪺���ʤ�V (0~360)
	float 					_cSpeed;			// ���⪺���ʳt��
	float					_cMaxSpeed;	// ���⪺�̰��t��
	float					_cAccSpeed;	// ���⪺�[�t�� (²�檺���N�O�X�����@��[�̰ܳ��t)
	float					_cDecSpeed;	// ���⪺��t�� (²�檺���N�O�X�����@���̧ܳC�t)
	float					_cTunSpeed;	// ���⪺���s�t�� (�u�b�V�q�[�k�Ҧ�����) (0 ~ 100)

	int _cSpriteX;
	float _cSpriteNowX;
	int _cSpriteY;
	float _cSpriteNowY;
	vector<int> _cSpriteOri;
	float _cSpriteWidth;
	float _cSpriteHeight;
	//vector<Bubble> _cBubble;		// ����o�g���w�w
};

#endif /* SYSTEM_CHARACTERSYSTEM_H_ */
