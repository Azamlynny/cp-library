from selenium import webdriver
from selenium.webdriver.common.keys import Keys
from bs4 import BeautifulSoup
import requests

contest_id = '1811'
problem_id = 'A'
page = 1
max_page = None

driver = webdriver.Chrome('./chromedriver')

while True:
    url = "http://codeforces.com/contest/"+contest_id+"/status/"+problem_id+"/page/" + str(page) + "?order=BY_ARRIVED_DESC"
    try:
        driver.get(url)
        source = requests.get(url).text
        print(source)
        break
    except:
        print("failed page ", page)
        break

    page+=1
