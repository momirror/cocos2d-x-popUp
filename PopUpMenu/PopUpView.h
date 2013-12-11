//
//  PopUpView.h
//  PopUpMenu
//
//  Created by msp on 13-12-11.
//
//

#ifndef __PopUpMenu__PopUpView__
#define __PopUpMenu__PopUpView__

#include <iostream>
#include "cocos2d.h"
using namespace cocos2d;

class PopUpView : public cocos2d::CCLayer
{
public:
    PopUpView(const char * bgImageName,const char * title,const char * message,const char * firstButtonTitle,SEL_MenuHandler  firstSel,const char * secondButtonTitle,SEL_MenuHandler secondSel,CCObject * delegate);
    ~PopUpView();
    static cocos2d::CCScene* scene();
    void OKButtonResponse();
    void CancelButtonResponse();
    void onEnter();
    bool ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent);
    
private:
    CCLabelTTF              * m_pTitleLabel;
    CCLabelTTF              * m_pMessageLabel;
    CCMenuItemFont          * m_pFirstButtonItem;
    CCMenuItemFont          * m_pSecondButtonItem;
    CCSprite                * m_pBgSprite;
    SEL_MenuHandler           m_firstSel;
    SEL_MenuHandler           m_secondSel;
    CCObject                * m_pDelegate;
};

#endif /* defined(__PopUpMenu__PopUpView__) */
