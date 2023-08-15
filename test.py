from selenium import webdriver
from selenium.webdriver.common.keys import Keys
from selenium.webdriver.common.by import By
from selenium.webdriver.support.wait import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
from webdriver_manager.chrome import ChromeDriverManager
import pprint
import datetime


driver = webdriver.Chrome(ChromeDriverManager(version='114.0.5735.90').install())

DataPath = 'comicData.txt'

with open(DataPath,'a',encoding='utf-8') as f:
        f.write('-----------------------------------------'+'\n')
        f.write(str(datetime.datetime.now())+'\n')
        f.write('-----------------------------------------'+'\n')


def my_serch(x):
        driver.get('https://www.baozimh.com/')
        driver.minimize_window()
        search = driver.find_element(By.CLASS_NAME,'pure-input')
        search.send_keys(x)
        search.send_keys(Keys.ENTER)

        mouse = driver.find_element(By.XPATH,'//*[@id="layout"]/div[2]/div[2]/div[1]/a[1]')
        mouse.click()

        dic = {driver.find_element(By.CLASS_NAME,'comics-detail__title').text:[
                (driver.find_element(By.XPATH,'//*[@id="layout"]/div[2]/div[1]/div[3]/div/div[2]/div/div[1]/div[2]/span/em')).text,
                (driver.find_element(By.XPATH,'//*[@id="layout"]/div[2]/div[1]/div[3]/div/div[2]/div/div[1]/div[2]/span/a')).text
                ]
        }
        with open(DataPath,'a',encoding='utf-8') as f:
                f.write(str(dic)+'\n')
                f.write('Comic_URL : '+driver.current_url+'\n')
        for i in dic:
                pprint.pprint(dic)

my_serch('武道獨尊')
my_serch('這一世我要當至尊')
my_serch('我師祖天下無敵')
my_serch('災難級英雄歸來')
my_serch('先尊落無極')
my_serch('徒弟都是女魔頭')
my_serch('我!天命大反派')
my_serch('大醫凌然')
my_serch('萬古神帝')
my_serch('SSS級自殺獵人')
my_serch('登入未來一萬年')
my_serch('江思先生')

with open(DataPath,'a',encoding='utf-8') as f:
        f.write('\n\n\n')
driver.quit()
