#include "stg/user_property.h"

USER_PROPERTIES::USER_PROPERTIES(const std::string & sd)
    : stat(),
      conf(),
      cash            (stat.cash,             "cash",             false, true, GetStgLogger(), sd, properties),
      up              (stat.monthUp,          "upload",           false, true, GetStgLogger(), sd, properties),
      down            (stat.monthDown,        "download",         false, true, GetStgLogger(), sd, properties),
      lastCashAdd     (stat.lastCashAdd,      "lastCashAdd",      false, true, GetStgLogger(), sd, properties),
      passiveTime     (stat.passiveTime,      "passiveTime",      false, true, GetStgLogger(), sd, properties),
      lastCashAddTime (stat.lastCashAddTime,  "lastCashAddTime",  false, true, GetStgLogger(), sd, properties),
      freeMb          (stat.freeMb,           "freeMb",           false, true, GetStgLogger(), sd, properties),
      lastActivityTime(stat.lastActivityTime, "lastActivityTime", false, true, GetStgLogger(), sd, properties),

      password    (conf.password,     "password",     true,  false, GetStgLogger(), sd, properties),
      passive     (conf.passive,      "passive",      false, false, GetStgLogger(), sd, properties),
      disabled    (conf.disabled,     "disabled",     false, false, GetStgLogger(), sd, properties),
      disabledDetailStat(conf.disabledDetailStat, "DisabledDetailStat", false, false, GetStgLogger(), sd, properties),
      alwaysOnline(conf.alwaysOnline, "alwaysOnline", false, false, GetStgLogger(), sd, properties),
      tariffName  (conf.tariffName,   "tariff",       false, false, GetStgLogger(), sd, properties),
      nextTariff  (conf.nextTariff,   "next tariff",  false, false, GetStgLogger(), sd, properties),
      address     (conf.address,      "address",      false, false, GetStgLogger(), sd, properties),
      note        (conf.note,         "note",         false, false, GetStgLogger(), sd, properties),
      group       (conf.group,        "group",        false, false, GetStgLogger(), sd, properties),
      email       (conf.email,        "email",        false, false, GetStgLogger(), sd, properties),
      phone       (conf.phone,        "phone",        false, false, GetStgLogger(), sd, properties),
      realName    (conf.realName,     "realName",     false, false, GetStgLogger(), sd, properties),
      credit      (conf.credit,       "credit",       false, false, GetStgLogger(), sd, properties),
      creditExpire(conf.creditExpire, "creditExpire", false, false, GetStgLogger(), sd, properties),
      ips         (conf.ips,          "ips",          false, false, GetStgLogger(), sd, properties),
      userdata0   (conf.userdata[0],  "userdata0",    false, false, GetStgLogger(), sd, properties),
      userdata1   (conf.userdata[1],  "userdata1",    false, false, GetStgLogger(), sd, properties),
      userdata2   (conf.userdata[2],  "userdata2",    false, false, GetStgLogger(), sd, properties),
      userdata3   (conf.userdata[3],  "userdata3",    false, false, GetStgLogger(), sd, properties),
      userdata4   (conf.userdata[4],  "userdata4",    false, false, GetStgLogger(), sd, properties),
      userdata5   (conf.userdata[5],  "userdata5",    false, false, GetStgLogger(), sd, properties),
      userdata6   (conf.userdata[6],  "userdata6",    false, false, GetStgLogger(), sd, properties),
      userdata7   (conf.userdata[7],  "userdata7",    false, false, GetStgLogger(), sd, properties),
      userdata8   (conf.userdata[8],  "userdata8",    false, false, GetStgLogger(), sd, properties),
      userdata9   (conf.userdata[9],  "userdata9",    false, false, GetStgLogger(), sd, properties)
{}
