DROP database IF EXISTS emind_software_center;
CREATE database emind_software_center;

--DROP USER IF EXISTS 'emindsoftwarecenter'@'localhost';
GRANT USAGE ON *.* TO 'emindsoftwarecenter'@'localhost';
DROP USER 'emindsoftwarecenter'@'localhost';

--CREATE USER 'emindsoftwarecenter'@'localhost' IDENTIFIED BY 'p#.!$!%(26i';
CREATE USER 'emindsoftwarecenter'@'localhost' IDENTIFIED BY '1';
--GRANT SELECT,INSERT,UPDATE,DELETE ON emind_software_center.* TO 'emindsoftwarecenter'@'localhost';
GRANT ALL PRIVILEGES ON emind_software_center.* TO 'emindsoftwarecenter'@'localhost';

USE emind_software_center;

--DROP TABLE IF EXISTS `sc_category`;
CREATE TABLE `sc_category` (
	`ID` int(11) unsigned NOT NULL AUTO_INCREMENT,
	`category_name` varchar(255) NOT NULL,
	PRIMARY KEY (`ID`)  
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--DROP TABLE IF EXISTS `sc_product`;
CREATE TABLE `sc_product` (
	`ID` int(11) unsigned NOT NULL AUTO_INCREMENT,
	`category_ID` int(11) unsigned NOT NULL,
	`release_ID` int(11) unsigned NOT NULL,
	`product_name` varchar(255) NOT NULL,
	`vendor_name` varchar(255) NOT NULL,
	`icon_url` varchar(255) NOT NULL,
	`url` varchar(255) NOT NULL,
	`product_description` text NOT NULL,
	`product_grade` int(11) unsigned NOT NULL,
	`grade_count` int(11) unsigned NOT NULL,
	PRIMARY KEY (`ID`),
	INDEX (`category_ID`),
	INDEX (`product_name`),
	INDEX (`vendor_name`),
	CONSTRAINT `sc_product_ibfk_1` FOREIGN KEY (`category_ID`) REFERENCES `sc_category` (`ID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--ALTER TABLE `sc_product` ADD INDEX (
	--`CategoriesID`
--)

--DROP TABLE IF EXISTS `sc_release`;
CREATE TABLE `sc_release` (
	`ID` int(11) unsigned NOT NULL AUTO_INCREMENT,
	`product_ID` int(11) unsigned NOT NULL,
	`version` varchar(255) NOT NULL,
	`icon_url` varchar(255) NOT NULL,
	`download_url` text NOT NULL,
	`changelog` text NOT NULL,
	`package_size` int(11) unsigned NOT NULL,
	`package_type` tinyint unsigned NOT NULL,
	`release_grade` int(11) unsigned NOT NULL,
	`grade_count` int(11) unsigned NOT NULL,
	`release_date` datetime DEFAULT NOW(),
	PRIMARY KEY (`ID`),
	CONSTRAINT	`sc_release_ibfk_1` FOREIGN KEY (`product_ID`) REFERENCES `sc_product` (`ID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--DROP TABLE IF EXISTS `sc_user`;
CREATE TABLE `sc_user` (
	`ID` int(11) unsigned NOT NULL AUTO_INCREMENT,
	`user_name` varchar(255) NOT NULL,
	`avatar_url` varchar(255) NOT NULL,
	`mail` varchar(255) NOT NULL,
	PRIMARY KEY (`ID`)  
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--DROP TABLE IF EXISTS `sc_banners`;
CREATE TABLE `sc_banners` (
	`ID` int(11) unsigned NOT NULL,
	`priority` tinyint unsigned NOT NULL,
	PRIMARY KEY (`ID`),
	CONSTRAINT	`sc_banners_ibfk_1` FOREIGN KEY (`ID`) REFERENCES `sc_product` (`ID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--DROP TABLE IF EXISTS `sc_comment`;
CREATE TABLE `sc_comment` (
	`ID` int(11) unsigned NOT NULL AUTO_INCREMENT,
	`product_ID` int(11) unsigned NOT NULL,
	`release_ID` int(11) unsigned NOT NULL,
	`user_ID` int(11) unsigned NOT NULL,
	`comment_text` text NOT NULL,
	`comment_grade` tinyint unsigned NOT NULL,
	`comment_Date` datetime DEFAULT NOW(),
	PRIMARY KEY (`ID`), 
	CONSTRAINT	`sc_comment_ibfk_1` FOREIGN KEY (`product_ID`) REFERENCES `sc_product` (`ID`),
	CONSTRAINT	`sc_comment_ibfk_2` FOREIGN KEY (`release_ID`) REFERENCES `sc_release` (`ID`),
	CONSTRAINT	`sc_comment_ibfk_3` FOREIGN KEY (`user_ID`) REFERENCES `sc_user` (`ID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--DROP TABLE IF EXISTS `sc_recommend`;
CREATE TABLE `sc_recommend` (
	`ID` int(11) unsigned NOT NULL,
	`priority` tinyint unsigned NOT NULL,
	PRIMARY KEY (`ID`),
	CONSTRAINT	`sc_recommend_ibfk_1` FOREIGN KEY (`ID`) REFERENCES `sc_product` (`ID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--DROP TABLE IF EXISTS `sc_screen_image`;
CREATE TABLE `sc_screen_image` (
	`ID` int(11) unsigned NOT NULL AUTO_INCREMENT,
	`product_ID` int(11) unsigned NOT NULL,
	`release_ID` int(11) unsigned NOT NULL,
	`image_url` varchar(255) NOT NULL,
	PRIMARY KEY (`ID`),
	CONSTRAINT	`sc_screen_image_ibfk_1` FOREIGN KEY (`product_ID`) REFERENCES `sc_product` (`ID`),
	CONSTRAINT	`sc_screen_image_ibfk_2` FOREIGN KEY (`release_ID`) REFERENCES `sc_release` (`ID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

