-- 프로그래머스 가격이 제일 비싼 식품의 정보 출력하기
SELECT * 
FROM FOOD_PRODUCT
WHERE PRICE = 
(SELECT MAX(PRICE) AS PRICE FROM FOOD_PRODUCT);
