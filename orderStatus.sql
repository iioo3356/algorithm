-- 조건별로 분류하여 주문상태 출력하기
SELECT 
ORDER_ID, PRODUCT_ID, OUT_DATE, 
IF(OUT_DATE IS NULL, "출고미정", 
   IF(DATEDIFF(OUT_DATE, "2022-05-01") <= 0, "출고완료", "출고대기")) AS 출고여부
FROM FOOD_ORDER
ORDER BY ORDER_ID;
