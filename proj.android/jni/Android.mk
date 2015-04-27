LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

$(call import-add-path,$(LOCAL_PATH)/../../cocos2d)
$(call import-add-path,$(LOCAL_PATH)/../../cocos2d/external)
$(call import-add-path,$(LOCAL_PATH)/../../cocos2d/cocos)

LOCAL_MODULE := cocos2dcpp_shared

LOCAL_MODULE_FILENAME := libcocos2dcpp

LOCAL_SRC_FILES := hellocpp/main.cpp \
                   ../../Classes/AppDelegate.cpp \
                   ../../Classes/myCocos2dFunc.cpp \
                   ../../Classes/Scene/MainScene.cpp \
                   ../../Classes/Scene/GameModeScene.cpp \
                   ../../Classes/Scene/GameStageScene.cpp \
                   ../../Classes/Scene/GameTimeScene.cpp \
                   ../../Classes/Scene/GameResultScene.cpp \
                   ../../Classes/Scene/GameGuildScene.cpp \
                   ../../Classes/Scene/SettingScene.cpp \
                   ../../Classes/Scene/RankScene.cpp \
                   ../../Classes/Scene/AboutScene.cpp \
                   ../../Classes/System/StageSystem.cpp \
                   ../../Classes/System/CharacterSystem.cpp \
                    ../../Classes/System/BubbleSystem.cpp \
                   ../../Classes/System/ItemSystem.cpp \
                   ../../Classes/System/GameSystem.cpp \
                   ../../Classes/System/DataSystem.cpp

LOCAL_C_INCLUDES := $(LOCAL_PATH)/../../Classes

# _COCOS_HEADER_ANDROID_BEGIN
# _COCOS_HEADER_ANDROID_END


LOCAL_STATIC_LIBRARIES := cocos2dx_static

# _COCOS_LIB_ANDROID_BEGIN
# _COCOS_LIB_ANDROID_END

include $(BUILD_SHARED_LIBRARY)

$(call import-module,.)

# _COCOS_LIB_IMPORT_ANDROID_BEGIN
# _COCOS_LIB_IMPORT_ANDROID_END
