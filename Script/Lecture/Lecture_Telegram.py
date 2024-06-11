import telepot
pot = telepot.Bot('6796860991:AAGLtFidisxjOefcOrZCJSFk1OvW2ICmBKc')
bot.getMe()

bot.sendMessage('7100560834', '임시 메시지')

url = 'http://openapi.molit.go.kr:8081/OpenAPI_ToolInstallPackage/service/rest/RTMSOBJSvc/getRTMSDataSvcAptTrade?serviceKey=sea100UMmw23Xycs33F1EQnumONR%2F9ElxBLzkilU9Yr1oT4TrCot8Y2p0jyuJP72x9rG9D8CN5yuEs6AS2sAiw%3D%3D&LAWD_CD=11110&DEAL_YMD=201712'

response = urlopen(url).read().decode('utf-8')
print(response)