#ifndef __GLOBALDATA_H__
#define __GLOBALDATA_H__
/*********************************************************************************
文件包含区
*********************************************************************************/
#include "include.h"
/*********************************************************************************
宏定义区
*********************************************************************************/
#define HistoryDataMaxNum       200
#define HistoryDataSize         9
//#define ADC1_DR_ADDRESS                         ((uint16_t)0x5344)
//#define ADC1_SAMPLE_BUFFER_SIZE                 ((uint8_t) 0x02)
//#define ADC1_SAMPLE_BUFFER_ADDRESS              ((uint16_t)(&ADC1SampleBuffer))
/*********************************************************************************
数据类型定义
*********************************************************************************/
enum Device_Status_EN
{
 RUN,   //运行
 SLEEP  //睡眠
};
struct Meter_Parameter_EN
{ 
  u8 MeterNumber[7];                    //表号
  u16 AlarmVoltage;                     //电池告警电压
  u8 SettleDate;                        //结算日期
  u16 ReportFrequency;                  //上报频率，分
  u16 SampleFrequency;                  //采样频率, 分
  u8 FirstReportHour;                   //首次上报时位
  u8 FirstReportMinute;                 //首次上报分位
  u8 ReportRandTiming;                  //上报随机计时，秒
  u32 ReportTiming;                     //上报计时，秒
  u32 SampleTiming;                     //采样计时，秒
  u32 SaveFlowTiming;                   //保存水量计时，秒
  u32 DeviceRunTiming;                  //设备运行计时, 秒
  enum Device_Status_EN DeviceStatus;  //设备状态  
  signed char Temp;                   //温度
  u16 Voltage;                          //电压 
};

typedef struct 
{ 
  u8 Front;     //头
  u8 Rear;      //尾
  u8 Total;     //总数
}History_Data_TypeDef;
/*********************************************************************************
常量定义区
*********************************************************************************/
/*********************************************************************************
公共变量定义区
*********************************************************************************/
extern RTC_TimeTypeDef   RTC_TimeStr;        //RTC时间结构体
extern RTC_DateTypeDef   RTC_DateStr;        //RTC日期结构体
extern struct Meter_Parameter_EN MeterParameter;
extern History_Data_TypeDef HistoryData;
/*********************************************************************************
外部变量声明区
*********************************************************************************/
/*********************************************************************************
私有变量定义区
*********************************************************************************/ 
/*********************************************************************************
测试变量定义区
*********************************************************************************/
/*********************************************************************************
内部函数定义区
*********************************************************************************/
/*********************************************************************************
功能代码定义区
*********************************************************************************/
unsigned short CRC16(unsigned char* data,unsigned short length);
unsigned char Sum_Check(unsigned char *sdata,unsigned short NUM);                //计算和校验
unsigned char Int_to_ASCLL(unsigned char data);
unsigned char ASCLL_to_Int(unsigned char data);
unsigned char BCD_to_Int(unsigned char data);
char* strnstr(char* str1,char* str2,unsigned char len);
unsigned char Check_Sum8(unsigned char *data,unsigned short length);
/*********************************************************************************/
#endif
/******************************************END********************************************************/