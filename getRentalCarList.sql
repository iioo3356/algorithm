-- 대여 기록이 존재하는 자동차 리스트 구하기
SELECT C.CAR_ID
FROM CAR_RENTAL_COMPANY_CAR AS C JOIN CAR_RENTAL_COMPANY_RENTAL_HISTORY AS H
ON C.CAR_ID = H.CAR_ID
WHERE C.CAR_TYPE = "세단" AND DATE_FORMAT(H.START_DATE, "%Y-%m") = "2022-10"
GROUP BY C.CAR_ID
ORDER BY C.CAR_ID DESC;
