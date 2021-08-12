/ 1. Исходные данные /

SELECT `author`.*, `client`.*, `film`.*, `usluga`.*
FROM `author`
    LEFT JOIN `film` ON `film`.`Author of Film` = `author`.`AuthorID`
    LEFT JOIN `usluga` ON `usluga`.`FilmID` = `film`.`FilmID`
    LEFT JOIN `client` ON `usluga`.`ClientID` = `client`.`UniqueID`

/ 2. Список фильм по цене /
SELECT `film`.`Price`, `film`.`FilmID`
FROM `film`
WHERE `film`.`Price` < '500';


/ 3. Список клиентов по определенному адресу/
SELECT `client`.`Address`, `client`.`UniqueID`
FROM `client`
WHERE `client`.`Address` = 'Ришельевская 4';

/ 4.Алфавитный список клиентов /
SELECT `client`.`F`, `client`.`UniqueID`
FROM `client`
WHERE `client`.`F` BETWEEN 'П' AND 'Т' ;

/ 5. Запрос с расчетами /
   UPDATE `film` SET `price`=`price`* (1.3);
SELECT `client`.`F`, `client`.`I`, `client`.`O`, `film`.`Film`, `film`.`Price`
FROM `client`
    LEFT JOIN `usluga` ON `usluga`.`ClientID` = `client`.`UniqueID`
    LEFT JOIN `film` ON `usluga`.`FilmID` = `film`.`FilmID`
ORDER BY `client`.`F` ASC

    
/ 6. Запрос с параметрами /

 UPDATE `film` SET `price`=`price`/(22);
SELECT `client`.`UniqueID`, `film`.`Film`, `film`.`Price`
FROM `film`
    LEFT JOIN `usluga` ON `usluga`.`FilmID` = `film`.`FilmID`
    LEFT JOIN `client` ON `usluga`.`ClientID` = `client`.`UniqueID`
WHERE (`film`.`Film` ='Сегодня жизнь бесплатная')



/ 7. Фамилии и инициалы /

SELECT F, LEFT(I,1), LEFT(O,1) FROM client 

/ 8. Изменение регистра /

SELECT F, UPPER(F) as F FROM client

/ 9. Средняя цена /

SELECT AVG(Price) AS price FROM film

/ 10. Суммарная стоимость /
SELECT SUM(Price)
FROM film

/ 11. Количество фильм /

SELECT COUNT('ID of usluga') as count FROM usluga 







-I-I-I-I-I-I-I-I-I-I-I-I-I-I-I-I-I-I-I-I-I-I-I-I-I-I-I-I-I-I-I-I-I-I-I-I-I-I-I-I-I-I-I-I-I-I-I-I-I-I-I-I-I-I-I-I-I-I-I-I-I-I-I-I-I-I-I-I-I-I-I-I-I-I-I-I-I-I-I-I-
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
-I-I-I-I-I-I-I-I-I-I-I-I-I-I-I-I-I-I-I-I-I-I-I-I-I-I-I-I-I-I-I-I-I-I-I-I-I-I-I-I-I-I-I-I-I-I-I-I-I-I-I-I-I-I-I-I-I-I-I-I-I-I-I-I-I-I-I-I-I-I-I-I-I-I-I-I-I-I-I-I-

/ 1. New Table /

CREATE TABLE new_table AS SELECT * FROM author,client,usluga;

/ 3. 

 UPDATE
  Film
 SET
  price = price * 1.2
 WHERE
  1;


/ 4.


 DELETE
 FROM
  new_table
 WHERE
  F='Сергеев'
  
  / 5.
  
  
INSERT INTO new_table
(
  price
  )
 SELECT
  price
 FROM
  film
 WHERE
  1;

// Пришлось вставить костыль, и добавить колонку price в new_table вручную , т.к. что-то багалось, и уже после этого вносить командой значения, но работает!
