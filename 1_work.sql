-- phpMyAdmin SQL Dump
-- version 5.1.0
-- https://www.phpmyadmin.net/
--
-- Хост: 127.0.0.1
-- Время создания: Мар 15 2021 г., 22:07
-- Версия сервера: 10.4.18-MariaDB
-- Версия PHP: 8.0.3

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- База данных: `filmoteka`
--

-- --------------------------------------------------------

--
-- Структура таблицы `client`
--

CREATE TABLE `client` (
  `F` char(50) NOT NULL,
  `I` char(50) NOT NULL,
  `O` char(50) NOT NULL,
  `Adress` char(50) NOT NULL,
  `Date of birth` date NOT NULL,
  `UniqueID` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Дамп данных таблицы `client`
--

INSERT INTO `client` (`F`, `I`, `O`, `Adress`, `Date of birth`, `UniqueID`) VALUES
('Петров', 'Иван', 'Сергеевич', 'Бобрикова 35/Б', '2005-03-08', 1),
('Иванов', 'Александр', 'Олегович', 'Ликёрная 32', '2002-03-08', 2),
('Королёв', 'Павел', 'Дмитриевич', 'Самсонова 4', '2005-02-05', 3),
('Круглов', 'Алексей', 'Александрович', 'Кузина 11', '2006-04-14', 4),
('Кольцов', 'Константин', 'Спиридонович', 'Малая Бронная 12', '2001-11-08', 5),
('Стрелков', 'Валерий', 'Альбертович', 'Разбитых фанарей 9', '2009-05-19', 6),
('Иванков', 'Вячеслав', 'Альбертович', 'Пушкина 45', '2001-09-01', 7);

-- --------------------------------------------------------

--
-- Структура таблицы `film`
--

CREATE TABLE `film` (
  `Film` char(50) NOT NULL,
  `Author of Film` char(50) NOT NULL,
  `Price` int(11) NOT NULL,
  `FilmID` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Дамп данных таблицы `film`
--

INSERT INTO `film` (`Film`, `Author of Film`, `Price`, `FilmID`) VALUES
('Шварцнегер убивает', 'Квентин Тараканов', 1000, 1),
('Маньяк-убийца 4', 'Илья Кубанский', 900, 2),
('Кировоградское шоссе', 'Илья Квасов', 1100, 3),
('Дорога на дороге', 'Кирилл Очаковский', 1400, 4),
('Любовь без денег', 'Даниил Селивёрстов', 150, 5),
('Красный огонь:время перемен', 'Игорь Игорев', 400, 6),
('Красный огонь: поездка в Казань', 'Игорь Игорев', 50, 7);

-- --------------------------------------------------------

--
-- Структура таблицы `usluga`
--

CREATE TABLE `usluga` (
  `Date of giving` date NOT NULL,
  `Date of reversing` date NOT NULL,
  `ID of usluga` int(11) NOT NULL,
  `ClientID` int(11) NOT NULL,
  `FilmID` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Дамп данных таблицы `usluga`
--

INSERT INTO `usluga` (`Date of giving`, `Date of reversing`, `ID of usluga`, `ClientID`, `FilmID`) VALUES
('2021-03-09', '2021-03-10', 1, 1, 7),
('2021-03-10', '2021-03-11', 2, 1, 6),
('2021-03-02', '2021-03-04', 3, 5, 1),
('2021-03-02', '2021-03-04', 4, 5, 2),
('2021-03-28', '2021-03-29', 5, 3, 4),
('2021-03-23', '2021-03-24', 6, 3, 5),
('2021-04-01', '2021-04-03', 7, 4, 1),
('2021-03-09', '2021-03-10', 8, 4, 7),
('2021-03-09', '2021-03-29', 9, 2, 4),
('2021-03-10', '2021-03-12', 10, 2, 7),
('2021-03-02', '2021-03-03', 11, 6, 5),
('2021-03-02', '2021-03-04', 12, 6, 3),
('2021-03-09', '2021-03-11', 13, 7, 1),
('2021-03-10', '2021-03-24', 14, 7, 5);

--
-- Индексы сохранённых таблиц
--

--
-- Индексы таблицы `client`
--
ALTER TABLE `client`
  ADD PRIMARY KEY (`UniqueID`);

--
-- Индексы таблицы `film`
--
ALTER TABLE `film`
  ADD PRIMARY KEY (`FilmID`);

--
-- Индексы таблицы `usluga`
--
ALTER TABLE `usluga`
  ADD PRIMARY KEY (`ID of usluga`),
  ADD KEY `Usluga_fk0` (`ClientID`),
  ADD KEY `Usluga_fk1` (`FilmID`);

--
-- AUTO_INCREMENT для сохранённых таблиц
--

--
-- AUTO_INCREMENT для таблицы `client`
--
ALTER TABLE `client`
  MODIFY `UniqueID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=8;

--
-- AUTO_INCREMENT для таблицы `film`
--
ALTER TABLE `film`
  MODIFY `FilmID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=8;

--
-- AUTO_INCREMENT для таблицы `usluga`
--
ALTER TABLE `usluga`
  MODIFY `ID of usluga` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=15;

--
-- Ограничения внешнего ключа сохраненных таблиц
--

--
-- Ограничения внешнего ключа таблицы `usluga`
--
ALTER TABLE `usluga`
  ADD CONSTRAINT `Usluga_fk0` FOREIGN KEY (`ClientID`) REFERENCES `client` (`UniqueID`),
  ADD CONSTRAINT `Usluga_fk1` FOREIGN KEY (`FilmID`) REFERENCES `film` (`FilmID`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
