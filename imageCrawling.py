# 연예인 이름 입력 -> 구글 이미지 검색 -> 해당 
from urllib.request import urlretrieve
from selenium import webdriver
from selenium.webdriver.common.action_chains import ActionChains  
from selenium.webdriver.common.keys import Keys
from multiprocessing import Pool
import time
import os
from os import remove
import uuid
from functools import partial
from PIL import Image
import cv2

def createFolder(dir):
    try:
        if not os.path.exists(dir):
            os.makedirs(dir)
    except OSError:
        print('Creating Directory Error')

def image_check(keyword):
    path = '/home/kimhayeon/Downloads/'+keyword+'/'
    os.chdir(path)
    files = os.listdir(path)
    imgs = []
    for file in files:
        f = cv2.imread(file)
        imgs.append(f)
    count = 0
    for i in range(len(imgs)):
        h, w, c = imgs[i].shape
        if (h <300 or w < 300):
            print("이미지 크기가 너무 작습니다\n파일을 삭제합니다.")
            remove(path+files[i])
            count+=1
        else:
            print("이미지 크기가 적절")
    print("삭제된 총 개수", count)

def image_download(limit, keyword):
    path = '/home/kimhayeon/chromedriver'
    driver = webdriver.Chrome(path)

    createFolder('/home/kimhayeon/Downloads/'+keyword)
    url = f'https://www.google.com/search?q={keyword}&source=lnms&tbm=isch&sa=X&sqi=2&ved=2ahUKEwjzyoPwxOrzAhVEmGoFHcklDwMQ_AUoAXoECAEQAw&biw=639&bih=704&dpr=1.25'
    driver.get(url) #크롬을 열고 해당 url로 이동

    print("스크롤 중")
    elem = driver.find_element_by_tag_name("body")
    for i in range(60):
        elem.send_keys(Keys.PAGE_DOWN)
        time.sleep(0.1)

    try:
        driver.find_element_by_xpath('//*[@id="islmp"]/div/div/div/div[1]/div[4]/div[2]/input').click()
        #스크롤링 하다 보면 나오는 '이미지 더 보기' 버튼 클릭
        for i in range(60):
            elem.send_keys(Keys.PAGE_DOWN)
            time.sleep(0.1)
    except:
        pass

    img_urls = []
    images = driver.find_elements_by_css_selector("img.rg_i.Q4LuWd")
    
    for i in range(1, len(images)):
        try:
            if i<=limit:
                #원본 이미지 다운로드를 위한 url 수집
                driver.find_element_by_xpath('//*[@id="islrg"]/div[1]/div['+str(i)+']/a[1]/div[1]/img').click()
                img_urls.append(driver.find_element_by_xpath('//*[@id="Sva75c"]/div/div/div[3]/div[2]/c-wiz/div/div[1]/div[1]/div[2]/div/a/img').get_attribute('src'))
                driver.find_element_by_xpath('//*[@id="Sva75c"]/div/div/div[2]/a').click()
        except:
            continue
    
    # 프리뷰 이미지 url 
    # if image.get_attribute('src') != None:
    # img_urls.append(image.get_attribute('src'))

    # print(img_urls)

    print("다운로드 시작")
    for url in img_urls:
        try:
            img_uuid = uuid.uuid1()
            urlretrieve(url, '/home/kimhayeon/Downloads/'+keyword+'/'+str(img_uuid)+'-original'+'.jpg')
            print("다운로드 중...")
        except:
            continue

    print("다운로드 완료")
    image_check(keyword)
    driver.close()

if __name__ == '__main__':
    keywords = ['empty']
    while (keywords[-1].isdigit()==False):
        keywords = []
        keywords = input("검색을 원하는 인물을 %으로 구분해서 입력, 마지막엔 원하는 사진 개수 쓰기: ").split("%")
    limit = int(keywords[-1])
    keywords = keywords[:-1]
    print(keywords, limit)
    pool = Pool(processes=4) #멀티 프로세스 기능
    func = partial(image_download, limit)
    pool.map(func, keywords)
    pool.close()
    pool.join()
