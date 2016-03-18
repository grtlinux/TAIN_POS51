---------------------------------------------------------------------------------
---------------------------------------------------------------------------------
---------------------------------------------------------------------------------
[ AP ]
---------------------------------------------------------------------------------
< ibridge/ram/cfg/baa_trlist.cfg >   : bk_fep_agent 용

#송신
POS51|S|HWPOS000001|0671|계약등기_접수정보내역

---------------------------------------------------------------------------------
< ibridge/ib2/cfg/biz.properties >

[OFSPOS5101]
        DESCRIPTION      = 우체국 등기업무
        OBSERVATION_FLAG = Y
        RUN_SCRIPT       = /hw01/ibridge/ib2/shl/ibrun2 OFSPOS5101
        RUNNING_SERVER   = AP
        RUNNING_PROCESS  = /hw01/ibridge/ib2/bin/bfscom2
        RUNNING_TIME     = 0~00:25~23:55 | 1~00:25~23:55 | 2~00:25~23:55 | 3~00:25~23:55 | 4~00:25~23:55 | 5~00:25~23:55 | 6~00:25~23:55
[OFRPOS5101]
        DESCRIPTION      = 우체국 등기업무
        OBSERVATION_FLAG = Y
        RUN_SCRIPT       = /hw01/ibridge/ib2/shl/ibrun2 OFRPOS5101
        RUNNING_SERVER   = AP
        RUNNING_PROCESS  = /hw01/ibridge/ib2/bin/bfrcom2
        RUNNING_TIME     = 0~00:25~23:55 | 1~00:25~23:55 | 2~00:25~23:55 | 3~00:25~23:55 | 4~00:25~23:55 | 5~00:25~23:55 | 6~00:25~23:55

[OISPOS5101]
        DESCRIPTION      = 우체국 등기업무
        OBSERVATION_FLAG = N
        RUN_SCRIPT       = /hw01/ibridge/ib2/shl/ibrun2 OISPOS5101
        RUNNING_SERVER   = FEP
        RUNNING_PROCESS  = /hw01/ibridge/ib2/bin/biscom2
        RUNNING_TIME     = 0~00:25~23:55 | 1~00:25~23:55 | 2~00:25~23:55 | 3~00:25~23:55 | 4~00:25~23:55 | 5~00:25~23:55 | 6~00:25~23:55

[OIRPOS5101]
        DESCRIPTION      = 우체국 등기업무
        OBSERVATION_FLAG = N
        RUN_SCRIPT       = /hw01/ibridge/ib2/shl/ibrun2 OIRPOS5101
        RUNNING_SERVER   = FEP
        RUNNING_PROCESS  = /hw01/ibridge/ib2/bin/bircom2
        RUNNING_TIME     = 0~00:25~23:55 | 1~00:25~23:55 | 2~00:25~23:55 | 3~00:25~23:55 | 4~00:25~23:55 | 5~00:25~23:55 | 6~00:25~23:55

[BXSPOS5101]
        DESCRIPTION      = 우체국 등기업무
        OBSERVATION_FLAG = N
        RUN_SCRIPT       = /hw01/ibridge/ib2/shl/ibrun2 BXSPOS5101
        RUNNING_SERVER   = FEP
        RUNNING_PROCESS  = /hw01/ibridge/ib2/bin/bxspos
        RUNNING_TIME     = 0~00:25~23:55 | 1~00:25~23:55 | 2~00:25~23:55 | 3~00:25~23:55 | 4~00:25~23:55 | 5~00:25~23:55 | 6~00:25~23:55

[BXRPOS5101]
        DESCRIPTION      = 우체국 등기업무
        OBSERVATION_FLAG = N
        RUN_SCRIPT       = /hw01/ibridge/ib2/shl/ibrun2 BXRPOS5101
        RUNNING_SERVER   = FEP
        RUNNING_PROCESS  = /hw01/ibridge/ib2/bin/bxrpos
        RUNNING_TIME     = 0~00:25~23:55 | 1~00:25~23:55 | 2~00:25~23:55 | 3~00:25~23:55 | 4~00:25~23:55 | 5~00:25~23:55 | 6~00:25~23:55

---------------------------------------------------------------------------------
< ibridge/ib2/cfg/ofscom2.cfg >

OFSPOS5101|172.30.225.53:041110|0000|0010|우체국 대량등기     일괄배치

---------------------------------------------------------------------------------
< ibridge/ib2/cfg/ofrcom2.cfg >

OFRPOS5101|172.30.225.53:042110|0000|0010|우체국 대량등기  일괄배치

---------------------------------------------------------------------------------
---------------------------------------------------------------------------------


---------------------------------------------------------------------------------
---------------------------------------------------------------------------------
---------------------------------------------------------------------------------
[ FEP ]
---------------------------------------------------------------------------------
< ibridge/ib2/cfg/biz.properties >

[OFSPOS5101]
        DESCRIPTION      = 우체국 등기업무
        OBSERVATION_FLAG = Y
        RUN_SCRIPT       = /hw01/ibridge/ib2/shl/ibrun2 OFSPOS5101
        RUNNING_SERVER   = AP
        RUNNING_PROCESS  = /hw01/ibridge/ib2/bin/bfscom2
        RUNNING_TIME     = 0~00:25~23:55 | 1~00:25~23:55 | 2~00:25~23:55 | 3~00:25~23:55 | 4~00:25~23:55 | 5~00:25~23:55 | 6~00:25~23:55

[OFRPOS5101]
        DESCRIPTION      = 우체국 등기업무
        OBSERVATION_FLAG = Y
        RUN_SCRIPT       = /hw01/ibridge/ib2/shl/ibrun2 OFRPOS5101
        RUNNING_SERVER   = AP
        RUNNING_PROCESS  = /hw01/ibridge/ib2/bin/bfrcom2
        RUNNING_TIME     = 0~00:25~23:55 | 1~00:25~23:55 | 2~00:25~23:55 | 3~00:25~23:55 | 4~00:25~23:55 | 5~00:25~23:55 | 6~00:25~23:55

[OISPOS5101]
        DESCRIPTION      = 우체국 등기업무
        OBSERVATION_FLAG = Y
        RUN_SCRIPT       = /hw01/ibridge/ib2/shl/ibrun2 OISPOS5101
        RUNNING_SERVER   = FEP
        RUNNING_PROCESS  = /hw01/ibridge/ib2/bin/biscom2
        RUNNING_TIME     = 0~00:25~23:55 | 1~00:25~23:55 | 2~00:25~23:55 | 3~00:25~23:55 | 4~00:25~23:55 | 5~00:25~23:55 | 6~00:25~23:55

[OIRPOS5101]
        DESCRIPTION      = 우체국 등기업무
        OBSERVATION_FLAG = Y
        RUN_SCRIPT       = /hw01/ibridge/ib2/shl/ibrun2 OIRPOS5101
        RUNNING_SERVER   = FEP
        RUNNING_PROCESS  = /hw01/ibridge/ib2/bin/bircom2
        RUNNING_TIME     = 0~00:25~23:55 | 1~00:25~23:55 | 2~00:25~23:55 | 3~00:25~23:55 | 4~00:25~23:55 | 5~00:25~23:55 | 6~00:25~23:55

[BXSPOS5101]
        DESCRIPTION      = 우체국 등기업무
        OBSERVATION_FLAG = N
        RUN_SCRIPT       = /hw01/ibridge/ib2/shl/ibrun2 BXSPOS5101
        RUNNING_SERVER   = FEP
        RUNNING_PROCESS  = /hw01/ibridge/ib2/bin/bxspos
        RUNNING_TIME     = 0~00:25~23:55 | 1~00:25~23:55 | 2~00:25~23:55 | 3~00:25~23:55 | 4~00:25~23:55 | 5~00:25~23:55 | 6~00:25~23:55

[BXRPOS5101]
        DESCRIPTION      = 우체국 등기업무
        OBSERVATION_FLAG = N
        RUN_SCRIPT       = /hw01/ibridge/ib2/shl/ibrun2 BXRPOS5101
        RUNNING_SERVER   = FEP
        RUNNING_PROCESS  = /hw01/ibridge/ib2/bin/bxrpos
        RUNNING_TIME     = 0~00:25~23:55 | 1~00:25~23:55 | 2~00:25~23:55 | 3~00:25~23:55 | 4~00:25~23:55 | 5~00:25~23:55 | 6~00:25~23:55

---------------------------------------------------------------------------------
< ibridge/ib2/cfg/oircom2.cfg >

OIRPOS5101|NULL:041110|0000|0010|우체국대량등기 일괄배치

---------------------------------------------------------------------------------
< ibridge/ib2/cfg/oiscom2.cfg >

OISPOS5101|NULL:042110|111|0|1|0000|0000|우체국 대량등기  일괄배치

---------------------------------------------------------------------------------
---------------------------------------------------------------------------------
