-- 상품 별 오프라인 매출 구하기
SELECT P.PRODUCT_CODE AS PRODUCT_CODE, P.PRICE * SUM(O.SALES_AMOUNT) AS SALES
FROM PRODUCT AS P LEFT JOIN OFFLINE_SALE AS O
ON P.PRODUCT_ID = O.PRODUCT_ID
GROUP BY P.PRODUCT_CODE
ORDER BY SALES DESC, P.PRODUCT_CODE ASC;
