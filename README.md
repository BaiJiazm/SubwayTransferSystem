## 上海地铁换乘指南系统(SubwayTransferSystem)

#### 简介
本项目是在2017年暑期所写的上海地铁换乘指南系统，是从零学QT，在两周左右无借鉴任何相同或相似程序全部由自己一人完成的小项目。

个人觉得还是非常用心的，是一个不错的小项目。如果你有兴趣想借鉴学习或者觉得还不错的话，可以Star一下哦。

如果程序本身有任何Issue或者你在其中有什么问题，欢迎在[Issue](https://github.com/BaiJiazm/SubwayTransferSystem/issues)部分下提出或者联系[b110011@qq.com](http://mailto:b110011@qq.com)

#### 项目背景和要求
上海的地铁交通网络已经基本成型，建成的地铁线十多条，站点上百个，现需建立一个换乘指南打印系统，通过输入起点和终点站，打印出地铁换乘指南，指南内容包括起点站、换乘站、终点站。

* 图形化显示地铁网络结构，能动态添加地铁线路和地铁站点。
* 根据输入起点和终点站，显示地铁换乘指南。
* 通过图形界面显示乘除路径。

#### 功能介绍
主要功能包含地铁网络线路的查看，地铁换乘指南查询，动态添加线路站点等。

* 线路图查看：
  * 查看上海地铁网络线路图，包括通过键盘、鼠标拖放、放大缩小等简易查看操作；
  * 查看地铁线路信息，包括线路段、包含站点等；
  * 查看地铁站的详细信息，包括站点地理坐标、所属线路等
* 换乘指南查询：
  * 提供地铁换乘查询，可通过视图方便的查看乘坐路线和换乘路线；
  * 提供最小出行时间的换乘策略指南
  * 提供最小换乘次数的换乘策略指南
* 动态添加线路：
  * 动态添加线路，可根据需要新增线路；
  * 动态添加站点，可根据需要新增站点；
  * 动态添加连接，可根据需要新增站点连接；
  * 文本方式简易添加，方便快捷；
* 帮助：
  * 提供软件使用帮助和说明；
* 关于：
  * 提供软件制作信息；

#### 开发平台

* 计算机型号	：惠普Pavilion M4
* 计算机内存	：4.00GB
* CPU       ：Intel Core i5  2.6GHz
* 操作系统	：Windows 10 家庭版
* 开发语言	：C++（C++11标准以上）
* 开发框架	：QT
* 集成开发环境：Qt Version 5.9.1
* 编译器		：MinGW 32bit
* 运行环境   ：
	* 可在上述集成环境下运行；
	* 通过windeployqt.exe及Enigma Virtual Box进行整合压缩为发布为了一个LinkListVisualizer.exe文件，可在普通windows机型下运行。

### 主要功能预览

##### 总览图
![总览图](https://i.imgur.com/B43tUl3.png)

##### 线路查询1
![线路查询1](https://i.imgur.com/wU1ZIi7.png)

##### 线路查询2
![线路查询2](https://i.imgur.com/e3i4ZfH.png)

##### 添加新线路
![添加新线路](https://i.imgur.com/A0qV2e9.png)

##### 添加新站点
![添加新站点](https://i.imgur.com/VunwdCG.png)

##### 添加新连接
![添加新连接](https://i.imgur.com/reS7WPo.png)

##### 文本方式直接添加
![文本添加](https://i.imgur.com/a5R3cxt.png)

##### 视图查看放大
* 点击工具栏中放大按钮；
* 或选择“视图”下“放大”；
* 或按下快捷键“Ctrl+L”；
* 或直接在视图区域进行鼠标滚轮放大操作
* 可进行视图的放大，方便查看。

![视图放大](https://i.imgur.com/a4Lh7B0.png)

##### 视图查看缩小
* 点击工具栏中缩小按钮；
* 或选择“视图”下“缩小”；
* 或按下快捷键“Ctrl+S”；
* 或直接在视图区域进行鼠标滚轮缩小操作
* 可进行视图的缩小，方便查看。

![视图缩小](https://i.imgur.com/u2tTXjh.png)

##### 鼠标悬停1
* 鼠标除能直接放大和缩小视图外，在查看视图信息有重要作用：
* 鼠标滚轮直接放大缩小视图；
* 通过鼠标点击后拖动，可直接进行视图移动；
* 将鼠标悬停在站点上，会提示站点的详细信息，如悬停在“曹杨路”站上，会有曹杨路地铁站的详细信息；

![鼠标悬停1](https://i.imgur.com/wtCM7YL.png)

##### 鼠标悬停2
* 将鼠标悬停在线路上，会提示线路的详细信息，如悬停在“曹杨路”站和“镇坪路”之间线路上，会有线路的详细信息；

![鼠标悬停2](https://i.imgur.com/lKIhLhr.png)

#### 项目结构
```
---/SubwayTransferSystem
     ---/功能源码
   /build-SubwayTransferSystem-Desktop_Qt_5_9_1_MinGW_32bit-Release
     ---/release文件
   /dealData
     ---/数据处理模块
   /osmXmlParser
     ---/数据处理模块
   /SubwayTransferSystem_boxed.exe
   /README.md
   /设计说明书.docx
```

#### 更多
了解项目的更多信息，请查看文档[设计说明书](https://github.com/BaiJiazm/SubwayTransferSystem/blob/queryByMinwindow/%E8%AE%BE%E8%AE%A1%E8%AF%B4%E6%98%8E%E4%B9%A6.docx)
