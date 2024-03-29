-- 조건에 부합하는 중고거래 댓글 조회하기
SELECT B.TITLE, B.BOARD_ID, R.REPLY_ID, R.WRITER_ID, R.CONTENTS, DATE_FORMAT(R.CREATED_DATE, "%Y-%m-%d") FROM USED_GOODS_BOARD AS B JOIN USED_GOODS_REPLY AS R ON B.BOARD_ID = R.BOARD_ID WHERE DATE_FORMAT(B.CREATED_DATE, "%Y-%m") = DATE_FORMAT(now(), "2022-10") ORDER BY R.CREATED_DATE ASC, B.TITLE ASC;
