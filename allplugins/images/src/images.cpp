﻿#include "images.h"


// 默认最多保存多少张图
#define MAX_IMAGE_SIZE 100

Images::Images(QObject*)
{
    /**
      * 设置Dll类型 后期优化的时候需要使用
     */
    setProperty("dllType",MSG_DLL_IMAGES);
    m_uiObject = nullptr;
    Q_INIT_RESOURCE(images);
}

void Images::loadUI()
{
    /**
    * @brief: 添加测试按钮控件增加
    *
    */
    if (m_uiObject != nullptr)
    {
        QWidget* pMainWidget = dynamic_cast<QWidget*>(m_uiObject);

        // 布局设置开始
        m_pHboxLayout = new QHBoxLayout();
        m_pHboxLayout->setSpacing(0);
        m_pHboxLayout->setMargin(0);
        QVBoxLayout* vBoxLayout = (QVBoxLayout*)pMainWidget->layout();
        vBoxLayout->addLayout(m_pHboxLayout);
        // 布局设置结束

        m_pLocalBtn = QSharedPointer<DTButton>(new DTButton(nullptr),&QObject::deleteLater);
        m_pLocalBtn->setText("本地草稿");
        m_pLocalBtn->setIcon(QIcon(":/resources/folder.png"));
        m_pLocalBtn->setStyleSheet("QPushButton {background-color: rgb(36, 36, 37); color:rgb(250, 250, 250); font: 12px; font-family:'Microsoft YaHei'; border-radius: 14px;}"
                                  "QPushButton:hover {background-color: rgb(38, 38, 38);}"
                                  "");
        m_pLocalBtn->setFixedSize(QSize(180,40));
        m_pLocalBtn->show();


        m_pCloudBtn = QSharedPointer<DTButton>(new DTButton(nullptr),&QObject::deleteLater);
        m_pCloudBtn->setText("我的空间");
        m_pCloudBtn->setIcon(QIcon(":/resources/folder.png"));
        m_pCloudBtn->setStyleSheet("QPushButton {background-color: rgb(36, 36, 37); color:rgb(250, 250, 250); font: 12px; font-family:'Microsoft YaHei'; border-radius: 14px;}"
                                  "QPushButton:hover {background-color: rgb(38, 38, 38);}"
                                  "");
        m_pCloudBtn->setFixedSize(QSize(180,40));
        m_pCloudBtn->show();

        m_pHotBtn = QSharedPointer<DTButton>(new DTButton(nullptr),&QObject::deleteLater);
        m_pHotBtn->setText("热门活动");
        m_pHotBtn->setIcon(QIcon(":/resources/folder.png"));
        m_pHotBtn->setStyleSheet("QPushButton {background-color: rgb(36, 36, 37); color:rgb(250, 250, 250); font: 12px; font-family:'Microsoft YaHei'; border-radius: 14px;}"
                                  "QPushButton:hover {background-color: rgb(38, 38, 38);}"
                                  "");
        m_pHotBtn->setFixedSize(QSize(180,40));
        m_pHotBtn->show();

        m_pSideBar = QSharedPointer<SideBarWidget>(new SideBarWidget(nullptr),&QObject::deleteLater);
        m_pSideBar->setFixedWidth(250);


        m_pAccountWidget = QSharedPointer<AccountWidget>(new AccountWidget(nullptr),&QObject::deleteLater);

        m_pAccountWidget->setFixedSize(QSize(200,100));

        m_pSideBar->layout()->addWidget(m_pAccountWidget.data());
        m_pSideBar->layout()->addWidget(m_pLocalBtn.data());
        m_pSideBar->layout()->addWidget(m_pCloudBtn.data());
        m_pSideBar->layout()->addWidget(m_pHotBtn.data());
        m_pHboxLayout->addWidget(m_pSideBar.data());
        m_pHboxLayout->addStretch();


//        pMainWidget->setLayout(m_pHboxLayout);

//        m_pHboxLayout->addWidget(m_pTestBtn.data(),20,Qt::AlignRight);


    }

}

QVariant Images::slotHandleMessage(const PluginMetaData &plt)
{
    // 同步消息处理
    return QVariant("");
}

void Images::slotEventFromPlugins(const PluginMetaData& plt)
{
    // 异步事件

    m_uiObject = plt.qObject;
    switch (plt.enumUiMsg) {
    case E_UI_MSG_TYPE::MSG_UI_NONE:
        break;
    default:
        break;
    }
}
