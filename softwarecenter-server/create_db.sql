DROP database IF EXISTS EmindSoftwareCenter;
CREATE database EmindSoftwareCenter;

--DROP USER IF EXISTS 'emindsoftwarecenter'@'localhost';
GRANT USAGE ON *.* TO 'emindsoftwarecenter'@'localhost';
DROP USER 'emindsoftwarecenter'@'localhost';

CREATE USER 'emindsoftwarecenter'@'localhost' IDENTIFIED BY 'p#.!$!%(26i';
GRANT SELECT,INSERT,UPDATE,DELETE ON EmindSoftwareCenter.* TO 'emindsoftwarecenter'@'localhost';

USE EmindSoftwareCenter;

--DROP TABLE IF EXISTS `sc_category`;
CREATE TABLE `sc_category` (
	`CategoryID` int(11) unsigned NOT NULL AUTO_INCREMENT,
	`CategoryName` varchar(255) NOT NULL,
	PRIMARY KEY (`CategoryID`)  
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--DROP TABLE IF EXISTS `sc_product`;
CREATE TABLE `sc_product` (
	`ProductID` int(11) unsigned NOT NULL AUTO_INCREMENT,
	`CategoryID` int(11) unsigned DEFAULT 0,
	`ReleaseID` int(11) unsigned DEFAULT 0,
	`ProductName` varchar(255) DEFAULT NULL,
	`VendorName` varchar(255) DEFAULT NULL,
	`IconUrl` varchar(255) DEFAULT '',
	`Url` varchar(255) DEFAULT NULL,
	`ProductDescription` text DEFAULT NULL,
	`ProductGrade` int(11) unsigned DEFAULT 0,
	`GradeCount` int(11) unsigned DEFAULT 0,
	PRIMARY KEY (`ProductID`),
	INDEX (`CategoryID`),
	INDEX (`ProductName`),
	INDEX (`VendorName`),
	CONSTRAINT `sc_product_ibfk_1` FOREIGN KEY (`CategoryID`) REFERENCES `sc_category` (`CategoryID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--ALTER TABLE `sc_product` ADD INDEX (
	--`CategoriesID`
--)

--DROP TABLE IF EXISTS `sc_release`;
CREATE TABLE `sc_release` (
	`ReleaseID` int(11) unsigned NOT NULL AUTO_INCREMENT,
	`ProductID` int(11) unsigned DEFAULT 0,
	`Version` varchar(255) DEFAULT NULL,
	`IconUrl` varchar(255) DEFAULT NULL,
	`DownloadUrl` text DEFAULT NULL,
	`Changelog` text DEFAULT NULL,
	`PackageSize` int(11) unsigned DEFAULT 0,
	`PackageType` tinyint unsigned DEFAULT 0,
	`ReleaseGrade` int(11) unsigned DEFAULT 0,
	`GradeCount` int(11) unsigned DEFAULT 0,
	`ReleaseDate` datetime DEFAULT NOW(),
	PRIMARY KEY (`ReleaseID`),
	CONSTRAINT	`sc_release_ibfk_1` FOREIGN KEY (`ProductID`) REFERENCES `sc_product` (`ProductID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--DROP TABLE IF EXISTS `sc_user`;
CREATE TABLE `sc_user` (
	`UserID` int(11) unsigned NOT NULL AUTO_INCREMENT,
	`UserName` varchar(255) DEFAULT NULL,
	`UserAvatarURL` varchar(255) DEFAULT NULL,
	`UserMailURL` varchar(255) DEFAULT NULL,
	PRIMARY KEY (`UserID`)  
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--DROP TABLE IF EXISTS `sc_banners`;
CREATE TABLE `sc_banners` (
	`ProductID` int(11) unsigned NOT NULL,
	`Priority` tinyint unsigned NOT NULL,
	PRIMARY KEY (`ProductID`),
	CONSTRAINT	`sc_banners_ibfk_1` FOREIGN KEY (`ProductID`) REFERENCES `sc_product` (`ProductID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--DROP TABLE IF EXISTS `sc_comment`;
CREATE TABLE `sc_comment` (
	`CommentID` int(11) unsigned NOT NULL AUTO_INCREMENT,
	`ProductID` int(11) unsigned DEFAULT 0,
	`ReleaseID` int(11) unsigned DEFAULT 0,
	`UserID` int(11) unsigned DEFAULT 0,
	`CommentText` text DEFAULT NULL,
	`CommentGrade` tinyint unsigned DEFAULT 0,
	`CommentDate` datetime DEFAULT NOW(),
	PRIMARY KEY (`CommentID`), 
	CONSTRAINT	`sc_comment_ibfk_1` FOREIGN KEY (`ProductID`) REFERENCES `sc_product` (`ProductID`),
	CONSTRAINT	`sc_comment_ibfk_2` FOREIGN KEY (`ReleaseID`) REFERENCES `sc_release` (`ReleaseID`),
	CONSTRAINT	`sc_comment_ibfk_3` FOREIGN KEY (`UserID`) REFERENCES `sc_user` (`UserID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--DROP TABLE IF EXISTS `sc_recommend`;
CREATE TABLE `sc_recommend` (
	`ProductID` int(11) unsigned NOT NULL,
	`Priority` tinyint unsigned NOT NULL,
	PRIMARY KEY (`ProductID`),
	CONSTRAINT	`sc_recommend_ibfk_1` FOREIGN KEY (`ProductID`) REFERENCES `sc_product` (`ProductID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--DROP TABLE IF EXISTS `sc_screen_image`;
CREATE TABLE `sc_screen_image` (
	`ScreenImageID` int(11) unsigned NOT NULL AUTO_INCREMENT,
	`ProductID` int(11) unsigned DEFAULT 0,
	`ReleaseID` int(11) unsigned DEFAULT 0,
	`ScreenImageURL` varchar(255) DEFAULT NULL,
	PRIMARY KEY (`ScreenImageID`),
	CONSTRAINT	`sc_screen_image_ibfk_1` FOREIGN KEY (`ProductID`) REFERENCES `sc_product` (`ProductID`),
	CONSTRAINT	`sc_screen_image_ibfk_2` FOREIGN KEY (`ReleaseID`) REFERENCES `sc_release` (`ReleaseID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

