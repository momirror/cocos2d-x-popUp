//
//  PopUpView.cpp
//  PopUpMenu
//
//  Created by msp on 13-12-11.
//
//

#include "PopUpView.h"

PopUpView::PopUpView(const char * bgImageName,const char * title,const char * message,const char * firstButtonTitle,SEL_MenuHandler  firstSel,const char * secondButtonTitle,SEL_MenuHandler secondSel,CCObject * delegate)
{
    float fTitleHeight = 20.0f;
    float fBtnHeight = 25.0f;
    this->setTouchEnabled(true);
    CCSize winSize = CCDirector::sharedDirector()->getWinSize();
    
    m_pBgSprite = CCSprite::create(bgImageName);
    m_pBgSprite->setAnchorPoint(ccp(0.5,0.5));
    m_pBgSprite->setPosition(ccp(winSize.width/2,winSize.height/2));
    this->addChild(m_pBgSprite);
    
    CCRect bgRect = m_pBgSprite->getTextureRect();
//    m_pTitleLabel = CCLabelTTF::create(title, "Arial", 15);
    CCSize titleSize = CCSizeMake(bgRect.size.width, fTitleHeight);
    m_pTitleLabel = CCLabelTTF::create(title, "Arial", 15, titleSize, kCCTextAlignmentCenter);
    
    m_pTitleLabel->setAnchorPoint(ccp(0,1));
    m_pTitleLabel->setPosition(ccp(bgRect.origin.x,bgRect.origin.y+bgRect.size.height));
    m_pBgSprite->addChild(m_pTitleLabel);
    
    CCRect titleRect = m_pTitleLabel->getTextureRect();
    CCSize MessageSize = CCSizeMake(bgRect.size.width, bgRect.size.height - 2*fTitleHeight);
    m_pMessageLabel = CCLabelTTF::create(message, "Arial", 15, MessageSize, kCCTextAlignmentCenter);
    m_pMessageLabel->setAnchorPoint(ccp(0,1));
    m_pMessageLabel->setPosition(ccp(titleRect.origin.x,bgRect.origin.y+bgRect.size.height - 1.3*fTitleHeight));
    m_pBgSprite->addChild(m_pMessageLabel);
    
    CCSprite * btn1Bg = CCSprite::create("btn1.png");
    btn1Bg->setAnchorPoint(ccp(0.5,0.5));
    btn1Bg->setPosition(ccp(bgRect.origin.x + 70,bgRect.origin.y+fBtnHeight));
    m_pBgSprite->addChild(btn1Bg);
    
    CCSprite * btn2Bg = CCSprite::create("btn2.png");
    btn2Bg->setAnchorPoint(ccp(0.5,0.5));
    btn2Bg->setPosition(ccp(bgRect.origin.x + 200,bgRect.origin.y+fBtnHeight));
    m_pBgSprite->addChild(btn2Bg);
    
    m_pFirstButtonItem = CCMenuItemFont::create(firstButtonTitle, this, menu_selector(PopUpView::OKButtonResponse));
    CCMenu * pFirstMenu = CCMenu::create(m_pFirstButtonItem,NULL);
    pFirstMenu->setPosition(btn1Bg->getPosition());
    m_pBgSprite->addChild(pFirstMenu);
    
    m_pSecondButtonItem = CCMenuItemFont::create(secondButtonTitle, this, menu_selector(PopUpView::CancelButtonResponse));
    CCMenu * pSecondMenu = CCMenu::create(m_pSecondButtonItem,NULL);
    pSecondMenu->setPosition(btn2Bg->getPosition());
    m_pBgSprite->addChild(pSecondMenu);

    m_firstSel = firstSel;
    m_secondSel = secondSel;
    m_pDelegate = delegate;

    
}

void PopUpView::OKButtonResponse()
{
    (m_pDelegate->*m_firstSel)(this);
}

void PopUpView::CancelButtonResponse()
{
    (m_pDelegate->*m_secondSel)(this);
}


PopUpView::~PopUpView()
{
    
}

void PopUpView::onEnter()
{
    CCLayer::onEnter();
    CCDirector* pDirector = CCDirector::sharedDirector();
    pDirector->getTouchDispatcher()->addTargetedDelegate(this, this->getTouchPriority(), true);
    
}

bool PopUpView::ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent)
{
    return true;//下层菜单不再响应触摸函数
}
