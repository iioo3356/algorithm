-- 조건에 부합하는 중고거래 상태 조회하기
SELECT BOARD_ID, WRITER_ID, TITLE, PRICE, 
CASE STATUS when "SALE" then '판매중'
		    when "RESERVED" then '예약중'
            when "DONE" then '거래완료'
            END AS STATUS
FROM USED_GOODS_BOARD
WHERE DATE_FORMAT(CREATED_DATE, "%Y-%m-%d") = "2022-10-05"
ORDER BY BOARD_ID DESC;
