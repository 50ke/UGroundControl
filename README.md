# UGroundControl
USV地面站

## 代码结构说明

| 目录                                         | 功能                                   | 说明                                                           |
|--------------------------------------------|--------------------------------------|--------------------------------------------------------------|
| [resources](resources)                     | 存放图片等资源文件                            | 在目录下添加图片后，需在[UGroundControl.qrc](UGroundControl.qrc)添加对应文件路径 |
| [Common](src%2FCommon)                     | Manager父类，可共享所有manager指针             | 可参考LinkManager类                                              |
| [LidarManager](src%2FLidarManager)         | 订阅处理雷达数据                             |                                                              |
| [LinkManager](src%2FLinkManager)           | 通信方式，LinkManager作为统一接口，XxxLink作为具体实现 | 当前仅有MqttLink，还需要添加SerialPortLink                             |
| [LinkProtocol](src%2FLinkProtocol)         | 存放所有Protobuf生成的文件                    | proto文件在UsvLink仓库                                            |
| [LogManager](src%2FLogManager)             | 日志管理模块                               | 运行程序后可在build目录下看到UGroundControl.log                          |
| [MapManager](src%2FMapManager)             | 加载导入的地图路径等                           |                                                              |
| [MissionManager](src%2FMissionManager)     | 任务管理模块，包含下载、上传等                      |                                                              |
| [MockManager](src%2FMockManager)           | 模拟船端数据交换逻辑                           |                                                              |
| [QmlControls](src%2FQmlControls)           | 自定义控件                                |                                                              |
| [QtLocationPlugin](src%2FQtLocationPlugin) | 自定义离线地图插件                            |                                                              |
| [SettingManager](src%2FSettingManager)     | 地面站设置                                |                                                              |
| [UI](src%2FUI)                             | 前端界面                                 |                                                              |
| [VehicleManager](src%2FVehicleManager)     | 无人船管理，包含无人船配置、切换、连接等                 |                                                              |
| [VideoManager](src%2FVideoManager)         | 视频流管理                                |                                                              |
| [UGroundControl.json](UGroundControl.json) | 地面站配置文件                              |                                                              |

## 主要未完成功能
### 流媒体展示（实验室同学还未反馈是否弄好）
### 遥控对接,参考：https://blog.csdn.net/liyuanbhu/article/details/65936340/、QGC-Joystick模块
### 串口通信收发protobuf消息
### 雷达数据对接
### 可能存在BUG和不完善的功能逻辑

## 次要未完善功能
### 地图切换功能