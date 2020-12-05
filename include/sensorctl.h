#ifndef __SENSORCTL_H
#define __SENSORCTL_H

#include <stdint.h>

#define ENABLE_LOGGING
#define MAX_SENSOR_NUM 15
#define MAX_SENSOR_NAME_LENGTH 20
#define MAX_BUS_NAME_LENGTH 16


//传感器类型
enum sensor_type_t {
    SENSOR_UNKNOW    = 0,
    SENSOR_AMC96     = 1, //amc96数显表
    SENSOR_BWDK326   , //变压器温控器
    SENSOR_ZWS5000   , //温湿度传感器
    SENSOR_SVG       , //无功补偿
    SENSOR_YJK       , //有载调压
    SENSOR_CHNTZS666 , //正泰电能表
    SENSOR_NRCSA01   , //综保
    SENSOR_GPS       , //GPS
};

//总线协议类型
enum bus_protocol_type_t {
    BUS_PROTOCOL_UNKNOW     = 0,
    BUS_PROTOCOL_MODBUS     = 1, //modbus--amc96  bwdk326  zws5000 svg
    BUS_PROTOCOL_DLT645     = 2, //dlt645--正泰电能表
    BUS_PROTOCOL_GPSMSG     = 3, //gps
    BUS_PROTOCOL_103STATUTE = 4, //103规约--综保设备使用
    BUS_PROTOCOL_PRIVATE    = 5 //yjk
};

//数显表招采的数据结构
typedef struct _amc96_data {
    float PhV_phsA ;        // A相电压
    float PhV_phsB ;        // B相电压
    float PhV_phsC ;        // C相电压
    float A_phsA ;          // A相电流
    float A_phsB ;          // B相电流
    float A_phsC ;          // C相电流
    float AllActivePower ;  // 总有功功率
    float ReactivePowerAll; // 总无功功率
    float AllPowerFactor ;  // 总功率因数 
} amc96_data_t;


//变压器温控器招采的数据结构
typedef struct _bwdk326_data {
    float Tmp_phsA ;      // A相温度
    float Tmp_phsB ;      // B相温度
    float Tmp_phsC ;      // C相温度
    float Tmp_mainRoom;  // 主变室温度
} bwdk326_data_t;

//温湿度传感器招采的数据结构
typedef struct _zws5000_data {
    float Temperature ;  // 温度
    float Humidity ;     // 湿度
} zws5000_data_t;

//无功补偿招采的数据结构
typedef struct _svg_data {
  float PhV_phsA;                    // A相电压
  float PhV_phsB;                    // B相电压
  float PhV_phsC;                    // C相电压
  float A_phsA;                      // A相电流
  float A_phsB;                      // B相电流
  float A_phsC;                      // C相电流
  float AllActivePower;              // 总有功功率
  float ReactivePowerAll;            // 总无功功率
  float AllPowerFactor;              // 总功率因数
  float ActualCompensationCapacity;  // 实际补偿容量

  int32_t ReactiveCompTermFailure;  // 无功补偿终端故障
  int32_t ReactiveCompWarning;      // 无功补偿告警
} svg_data_t;

//有载调压招采的数据结构
typedef struct _yjk_data {
    int32_t level; //档位
}yjk_data_t;

//正泰电能表招采的数据结构
typedef struct _chntzs666_data {
    float PhV_phsA ;            // A相电压
    float PhV_phsB ;            // B相电压
    float PhV_phsC ;            // C相电压
    float A_phsA ;              // A相电流
    float A_phsB ;              // B相电流
    float A_phsC ;              // C相电流
    float ZeroCurrent ;         // 零线电流
    float AllActivePower ;      // 总有功功率
    float ActivePower_phsA ;    // A相有功功率
    float ActivePower_phsB ;    // B相有功功率
    float ActivePower_phsC ;    // C相有功功率
    float ReactivePowerAll ;    // 总无功功率
    float ReactivePower_phsA ;  // A相无功功率
    float ReactivePower_phsB ;  // B相无功功率
    float ReactivePower_phsC ;  // C相无功功率
    float AllPowerFactor ;      // 总功率因数
    float PowerFactorA ;        // A功率因数
    float PowerFactorB ;        // B功率因数
    float PowerFactorC ;        // C功率因数
    float PhaseAngleA ;         // A相角
    float PhaseAngleB ;         // B相角
    float PhaseAngleC ;         // C相角

    // 正向有功最大需量及发生时间
    float AllMaxPower ;  // 总最大需量
    int64_t TimeOfMaxPower;          // 总需量发生时间

    // 电能示值数据
    float PositiveActivePower ;  // 正向有功电能示值（总、各费率）
    float PositiveReactivePower ;  // 正向无功电能示值
    float InverseActivePower ;  // 反向有功电能示值（总、各费率）
    float InverseReactivePower ;  // 反向无功电能示值
    float OneReactivePower ;      // 一象限无功电能示值
    float TwoReactivePower ;      // 二象限无功电能示值
    float ThreeReactivePower ;    // 三象限无功电能示值
    float FourReactivePower ;     // 四象限无功电能示值
    float CombinedActivePower ;   // 组合有功电能示值

    // 定时冻结
    int64_t Timing_frozenTime;  // 冻结时间
    // 变量数据
    float Timing_AllActivePower ;      // 总有功功率
    float Timing_ActivePower_phsA ;    // A相有功功率
    float Timing_ActivePower_phsB ;    // B相有功功率
    float Timing_ActivePower_phsC ;    // C相有功功率
    float Timing_ReactivePowerAll ;    // 总无功功率
    float Timing_ReactivePower_phsA ;  // A相无功功率
    float Timing_ReactivePower_phsB ;  // B相无功功率
    float Timing_ReactivePower_phsC ;  // C相无功功率

    // FrozenData
    float Timing_PositiveActivePower ;     // 正向有功电能数据
    float Timing_InverseActivePower ;      // 反向有功电能数据
    float Timing_CombinedReactivePower1 ;  // 组合无功1电能数据
    float Timing_CombinedReactivePower2 ;  // 组合无功2电能数据
    // 最大需量数据
    float Timing_AllMaxPower ;  // 总最大需量
    int64_t Timing_TimeOfMaxPower;          // 总需量发生时间

    // 瞬时冻结数据
    int64_t Momentary_frozenTime;  // 冻结时间
    // 变量数据
    float Momentary_AllActivePower ;      // 总有功功率
    float Momentary_ActivePower_phsA ;    // A相有功功率
    float Momentary_ActivePower_phsB ;    // B相有功功率
    float Momentary_ActivePower_phsC ;    // C相有功功率
    float Momentary_ReactivePowerAll ;    // 总无功功率
    float Momentary_ReactivePower_phsA ;  // A相无功功率
    float Momentary_ReactivePower_phsB ;  // B相无功功率
    float Momentary_ReactivePower_phsC ;  // C相无功功率
    // FrozenData
    float Momentary_PositiveActivePower ;  // 正向有功电能数据
    float Momentary_InverseActivePower ;   // 反向有功电能数据
    float Momentary_CombinedReactivePower1 ;  // 组合无功1电能数据
    float Momentary_CombinedReactivePower2 ;  // 组合无功2电能数据
    // 最大需量数据
    float Momentary_AllMaxPower ;  // 总最大需量
    int64_t Momentary_TimeOfMaxPower;          // 总需量发生时间

    /*---------------遥信------------------------------*/
    int32_t LossPressure ;         // 电能表失压
    int32_t OverPressure ;         // 电能表过压
    int32_t LossOfPhase ;          // 电能表断相
    int32_t LossCurrent ;          // 电能表失流
    int32_t OverCurrent ;          // 电能表过流
    int32_t ReversePower ;         // 电能表功率反向
    int32_t VoltageReversePhase ;  // 电能表电压逆相序
    int32_t PowerDown ;            // 电能表掉电
    int32_t VoltageUnbalance ;     // 电能表电压不平衡

} chntzs666_data_t;

//综保遥信数据
typedef struct _yao_xin{

    // 断路器用到的综保传感器的一般信号
    uint8_t     gatestat[30];            //表示30个开入开关 GateStat
    int32_t BreakerOpen;        // 断路器分位
    int32_t BreakerClose;       // 断路器合位
    int32_t HandcartSite;       // 手车工作位置
    int32_t GroundknifeClosed;  // 地刀合位
    int32_t SpringNoPower;      // 弹簧未储能
    int32_t NeedRepair;         // 置检修状态
    int32_t ResetSignal;        // 信号复归

    // 变压器用到的综保传感器的一般信号
    int32_t LightGasWarning;  // 轻瓦斯告警
    int32_t RegulateWarning;  // 调压轻瓦斯告警
    int32_t AirCoolingLost;   // 风冷消失告警
    int32_t SwitchChanged;    // 有载分接开关变位
    int32_t GearChanged;      // 就地调档控制

    // 综保传感器自身重要信号
    int32_t Accident;          // 综保故障
    int32_t CommunOutage;      // 通讯中断
    int32_t ControlBackBreak;  // 控回断线
    int32_t AccidentTimes;     // 事故总
    int32_t OneOverCurrent;    // 过流Ⅰ段动作
    int32_t TwoOverCurrent;    // 过流Ⅱ段动作
    int32_t OverLoad;          // 过负荷动作
    int32_t ZeroOverLoad;      // 零序过流Ⅰ段动作
    int32_t TvPowerOutage;     // TvPowerOutage

    // 变压器需要的综保传感器的重要信号
    int32_t HeavyGasWarning;      // 重瓦斯告警
    int32_t HeavyGasTrip;         // 重瓦斯跳闸
    int32_t RegulateGasWarning;   // 调压重瓦斯告警
    int32_t RegulateGasTrip;      // 调压重瓦斯跳闸
    int32_t HigtTempWarning;      // 温度高告警
    int32_t HigtTempTrip;         // 温度高跳闸
    int32_t HigtOilLevalWarning;  // 油位高告警
    int32_t HigtOilLevalTrip;     // 油位高跳闸
    int32_t LowOilLevalWarning;   // 油位低告警
    int32_t LowOilLevalTrip;      // 油位低跳闸
    int32_t PressReleaseWarning;  // 压力释放告警
    int32_t PressReleaseTrip;     // 压力释放跳闸

} yao_xin_t;

//综保遥测数据
typedef struct _yao_ce{
  float PhV_phsA;          // A相电压
  float PhV_phsB;          // B相电压
  float PhV_phsC;          // C相电压
  float A_phsA;            // A相电流
  float A_phsB;            // B相电流
  float A_phsC;            // C相电流
  float AllActivePower;    // 总有功功率
  float ReactivePowerAll;  // 总无功功率
  float AllPowerFactor;    // 总功率因数
} yao_ce_t;


//综保设备招采的数据结构
typedef struct _nrcsa01_data {
    yao_xin_t yx;//遥信数据
    yao_ce_t  yc;//遥测数据
} nrcsa01_data_t;


//GPS招采的数据结构
typedef struct _gps_data {
  int E_W;                                  //东西经 0 东经 1 西经
  int N_S;                                  //南北纬 0 北纬 1 南纬
  float Longitude;                   // 经度-已转换百度地图
  float Latitude;                    // 纬度-已转换百度地图
  float Atitude;                     // 海拔
  int nosv;//暂不使用
  int year;//年--已转本地时间
  int month;//月--已转本地时间
  int day;//日--已转本地时间
  int hour;//时--已转本地时间
  int min;//分--已转本地时间
  int sec;//秒--已转本地时间
} gps_data_t;


//传感器485配置参数
typedef struct _serial_param {
  int nSpeed;//波特率
  int nBits;//数据位
  int nStop;//停止位
  char nEvent;//奇偶校验位
} serial_param_t;

//传感器地址
typedef union _devaddr{
        int addr_int;//modbus的设备地址
        unsigned char addr_array[6];//正泰电能表的地址 (当设备为综保设备时，用于传递综保设备的ip地址)
}addt_t;

typedef struct _sensor {
    addt_t addr;//传感器的设备地址
    serial_param_t sparam;//传感器的通讯参数
    enum sensor_type_t sensor_type;//传感器类型
    char sensor_name[MAX_SENSOR_NAME_LENGTH];//传感器设备名字-每个传感器的名字不允许相同
} sensor_t;


//bus总线上下文
typedef struct _ensorctl_context sensorctl_context_t;


/* Maximum number of bytes in a log line */
#define SENSORCTL_MAX_LOG_LEN	1024
/* Terminator for log lines */
#define SENSORCTL_LOG_LINE_END	"\n"

enum sensorctl_log_level {
	/** (0) : No messages ever emitted by the library (default) */
	SENSORCTL_LOG_LEVEL_NONE = 0,

	/** (1) : Error messages are emitted */
	SENSORCTL_LOG_LEVEL_ERROR = 1,

	/** (2) : Warning and error messages are emitted */
	SENSORCTL_LOG_LEVEL_WARNING = 2,

	/** (3) : Informational, warning and error messages are emitted */
	SENSORCTL_LOG_LEVEL_INFO = 3,

	/** (4) : All messages are emitted */
	SENSORCTL_LOG_LEVEL_DEBUG = 4
};

#define SENSORCTL_PRINTFLIKE(formatarg, firstvararg) \
	__attribute__ ((__format__ (__printf__, formatarg, firstvararg)))


#ifdef ENABLE_LOGGING

void sensorctl_log(sensorctl_context_t *ctx, enum sensorctl_log_level level,
	const char *function, const char *format, ...) SENSORCTL_PRINTFLIKE(4, 5);

#define _sensorctl_log(ctx, level, ...) sensorctl_log(ctx, level, __func__, __VA_ARGS__)

#define sensorctl_err(ctx, ...)	_sensorctl_log(ctx, SENSORCTL_LOG_LEVEL_ERROR, __VA_ARGS__)
#define sensorctl_warn(ctx, ...)	_sensorctl_log(ctx, SENSORCTL_LOG_LEVEL_WARNING, __VA_ARGS__)
#define sensorctl_info(ctx, ...)	_sensorctl_log(ctx, SENSORCTL_LOG_LEVEL_INFO, __VA_ARGS__)
#define sensorctl_dbg(...)		_sensorctl_log(NULL, SENSORCTL_LOG_LEVEL_DEBUG, __VA_ARGS__)

#else /* ENABLE_LOGGING */

#define sensorctl_err(ctx, ...)	UNUSED(ctx)
#define sensorctl_warn(ctx, ...)	UNUSED(ctx)
#define sensorctl_info(ctx, ...)	UNUSED(ctx)
#define sensorctl_dbg(...)		do {} while (0)

#endif /* ENABLE_LOGGING */


//-----------------------------------------------------------------------------
// 初始化硬件设备使用环境，全局环境只需调用一次
//-----------------------------------------------------------------------------
//
// Return Value : success 0  failed -1
// Parameters   : None
// Read from the selected endpoint FIFO
//
//-----------------------------------------------------------------------------
int libsensorctl_init() ;


//-----------------------------------------------------------------------------
// 分配上下问空间，初始化上下文空间参数
//-----------------------------------------------------------------------------
//
// Return Value : success sensorctl_context_t *context  failed NULL
// Parameters   : None
//
//-----------------------------------------------------------------------------
sensorctl_context_t *bus_context_malloc();

//-----------------------------------------------------------------------------
// 初始化总线协议
//-----------------------------------------------------------------------------
//
// Return Value : success 0  failed -1
// Parameters   : 
//                1) sensorctl_context_t *context : Bus总线上下问
//                2) char *bus_name : 总线名字  eg. /dev/ttyS0 /dev/ttyUSB0
//                3) enum bus_protocol_type_t type : 总线协议类型
//
//-----------------------------------------------------------------------------
int bus_context_init(sensorctl_context_t *context, char *bus_name, enum bus_protocol_type_t type);


//-----------------------------------------------------------------------------
// 连接传感器
//-----------------------------------------------------------------------------
//
// Return Value : success 0  failed -1
// Parameters   : 
//                1) sensorctl_context_t *context : Bus总线上下问
//                2) sensor_t *sensor : 传感器参数
//                3) enum bus_protocol_type_t type : 传感器协议类型
//
//-----------------------------------------------------------------------------
int sensor_attach(sensorctl_context_t *context, sensor_t *sensor, enum sensor_type_t stype);


//-----------------------------------------------------------------------------
// 获取传感器数据
//-----------------------------------------------------------------------------
//
// Return Value : success 0  failed -1
// Parameters   : 
//                1) sensorctl_context_t *context : Bus总线上下问
//                2) sensor_t *sensor : 传感器类型
//                3) enum bus_protocol_type_t type : 该类型的数据buff地址
//
// 当同种类型的传感器只有一种时可以使用该接口
//-----------------------------------------------------------------------------
int sensor_get_data(sensorctl_context_t *context, enum sensor_type_t stype, void *data);


//-----------------------------------------------------------------------------
// 通过类型+传感器名字的方式获取传感器数据
//-----------------------------------------------------------------------------
//
// Return Value : success 0  failed -1
// Parameters   : 
//                1) sensorctl_context_t *context : Bus总线上下问
//                2) sensor_t *sensor : 传感器类型
//                3) char *name : 传感气名字
//                4) enum bus_protocol_type_t type : 该类型的数据buff地址
//
// 当同种类型的传感器有多个时则必须使用该接口  如：同一bus总线下连接了多个电能表
//-----------------------------------------------------------------------------
int sensor_get_data_by_name(sensorctl_context_t *context, enum sensor_type_t stype, char *name, void *data);


//-----------------------------------------------------------------------------
// 销毁总线上下文
//-----------------------------------------------------------------------------
//
// Return Value : success 0  failed -1
// Parameters   : 
//                1) sensorctl_context_t *context : Bus总线上下问
//
//-----------------------------------------------------------------------------
int bus_context_deinit(sensorctl_context_t *context);





#endif //__SENSORCTL_H