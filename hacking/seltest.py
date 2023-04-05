from selenium import webdriver
from selenium.webdriver.common.keys import Keys
from bs4 import BeautifulSoup
import requests
import os

contest_id = '1811'
problem_id = 'F'
directory = contest_id + '/' + problem_id

replace = {'&quot;': '\"', '&gt;': '>', '&lt;': '<', '&amp;': '&', "&apos;": "'"}
languages = {'GNU C++20 (64)', 'GNU C++14', 'GNU C++11', 'GNU C++17'} # , 'Java 8':'Java 11.0.5', 'Python 3': 'Python 3.7.2', 'Python 2':'Python 2.7.15'

def parse(code):
	for key in replace.keys():
		code = code.replace(key, replace[key])
	return code

#fetches the code corresponding to the parameter url
def getCode(submission_url, submission_id, contest_id):
    source = requests.get(submission_url).text
    soup = BeautifulSoup(source, 'html.parser')
    language = soup.findAll('td')[3].text[6:-6]
    # print(language)
    if language not in languages:
        return
    code = soup.findAll('pre')[0].text
    code = parse(code).replace('\r', '')
    if code != '':
        print("Create", submission_id + ".cpp")
        filewrite = open(directory + '/' + submission_id + '.cpp', 'w')
        filewrite.write(code)
        filewrite.close()


if (not os.path.exists(directory)):
    os.makedirs(directory)

options = webdriver.ChromeOptions()
options.add_experimental_option('excludeSwitches', ['enable-logging'])
driver = webdriver.Chrome('./chromedriver',options=options)

page = 1
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
            try:
                getCode(submission_url, submission['submissionid'], contest_id)
            except:
                continue

    except:
        print("Finished parsing on page:", page)
        # break

    page+=1

driver.quit()
