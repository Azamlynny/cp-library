from selenium import webdriver
from selenium.webdriver.common.keys import Keys
from bs4 import BeautifulSoup
import requests

contest_id = '1811'
problem_id = 'A'
page = 1
max_page = None

options = webdriver.ChromeOptions()
options.add_experimental_option('excludeSwitches', ['enable-logging'])
driver = webdriver.Chrome('./chromedriver',options=options)

while True:
    url = "http://codeforces.com/contest/"+contest_id+"/status/"+problem_id+"/page/" + str(page) + "?order=BY_ARRIVED_DESC"
    print ("Parsing page:", page)
    try:
        driver.get(url)
        source = requests.get(url).text
        soup = BeautifulSoup(source, 'html.parser')
        submissions = soup.findAll('a', {'class':'view-source'})
        
        for submission in submissions:
            submission_url = "http://codeforces.com" + submission['href']
            print(submission_url)
    except:
        print("Finished parsing on page:", page)
        break

    page+=1

driver.quit()
