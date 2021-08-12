SELECT * FROM author AS a INTO OUTFILE "E:\\author2.txt" LINES TERMINATED BY '\n';

SELECT * FROM client AS c INTO OUTFILE "E:\\client2.txt" LINES TERMINATED BY '\n';

SELECT * FROM film AS f INTO OUTFILE "E:\\film2.txt" LINES TERMINATED BY '\n';

SELECT * FROM usluga AS u INTO OUTFILE "E:\\usluga2.txt" LINES TERMINATED BY '\n';



DELETE FROM author;

DELETE FROM client;

DELETE FROM film;

DELETE FROM usluga;


  
  USE order;
  LOAD DATA INFILE "E:\author2.txt"
  INTO  TABLE author
  LINES TERMINATED BY '\n';


  USE order;
  LOAD DATA INFILE "E:\client2.txt"
  INTO  TABLE client
  LINES TERMINATED BY '\n';


  USE order;
  LOAD DATA INFILE "E:\film2.txt"
  INTO  TABLE film
  LINES TERMINATED BY '\n';

  USE order;
  LOAD DATA INFILE "E:\usluga2.txt"
  INTO  TABLE usluga
  LINES TERMINATED BY '\n';
