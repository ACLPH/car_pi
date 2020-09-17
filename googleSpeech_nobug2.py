#!/usr/bin/python
#coding:utf-8
import speech_recognition as sr
import time
import os
from os import path
def Chineseize(num):
       dict = {1:"一", 2:"二", 3:"三", 4: "四", 5:"五", 6:"六", 7:"七", 8:"八", 9:"九", 0:"零"}

       num = int(float(num))

       if num==0:
            num="零"
       elif num==10:
            num = "十"
       else:
             ch_num = str(num)   #int to str

             if len(ch_num)==1:
                   num = dict[num]
             elif len(ch_num)==2:
                   num = dict[int(ch_num[0])]+"十"+dict[int(ch_num[1])]
             elif len(ch_num)==3:
                   num = dict[int(ch_num[0])]+"百"+dict[int(ch_num[1])]+"十"+dict[int(ch_num[2])]
             elif len(ch_num)==4:
                   num = dict[int(ch_num[0])]+"千"+dict[int(ch_num[1])]+"百"+dict[int(ch_num[2])]+"十"+dict[int(ch_num[3])]
             elif len(ch_num)==5:
                    num = dict[int(ch_num[0])]+"萬"+dict[int(ch_num[1])]+"千"+dict[int(ch_num[2])]+"百"+dict[int(ch_num[3])]+"十"+dict[int(ch_num[4])]

       if num[len(num)-1]=="零":
            num[len(num)-1] = ""
            for i in range(len(num)):
                if num[i]=="零":
                       num[i+1]=""

       print(num)
       return num
os.system("arecord test.wav -f S16_LE -r 44100 -d 5")

AUDIO_FILE = path.join(path.dirname(path.realpath(__file__)),"test.wav")


r=sr.Recognizer()
with sr.AudioFile(AUDIO_FILE) as source:
         audio = r.record(source)

try:
       print("Google Speech Recognition thinks you said:")
       ans = r.recognize_google(audio, language="zh-TW")
       print(ans)

       file = open("OBDdata.txt","r")
       OBDdata = file.read();
       OBDdata = Chineseize(OBDdata)
       result = ""
       for i in range(len(ans)-1):
             if ans[i:i+2] == "轉速" or ans[i:i+2] == "引擎":
                    result = "現在的引擎轉速是每分鐘"+OBDdata+"轉"
                    break
             elif ans[i:i+2] == "車速" or  ans[i:i+2] == "速度":
                    result = "現在的行車速度是時速"+OBDdata+"公里"
                    break

       print(result)
       os.system("./tx2.o "+result+" 1")
except sr.UnknownValueError:
         print("Google Speech Recognition could not understand audio")
except sr.RequestError as e:
         print("Could not request results from Google Speech Recognition Serivce; {0}".format(e))

