
DROP DATABASE IF EXISTS db_rpg;
CREATE DATABASE db_rpg;

use db_rpg;

DROP TABLE IF EXISTS tbl_geschlecht;
CREATE TABLE tbl_geschlecht(
pk_geschlecht CHAR(1) PRIMARY KEY
)
ENGINE = InnoDB;

DROP TABLE IF EXISTS tbl_user_type;
CREATE TABLE tbl_user_type(
pk_user_type_id INT PRIMARY KEY AUTO_INCREMENT,
name VARCHAR(32)
)ENGINE = InnoDB;

DROP TABLE IF EXISTS tbl_user;
CREATE TABLE tbl_user(
pk_user_id INT PRIMARY KEY AUTO_INCREMENT,
username VARCHAR(32),
password VARCHAR(32),
email VARCHAR(64),
first_name VARCHAR(32),
last_name VARCHAR(32),
fk_geschlecht CHAR(1),
fk_user_type INT,
user_allow CHAR(1),
CONSTRAINT `user_type`
	FOREIGN KEY(fk_user_type) REFERENCES tbl_user_type(pk_user_type_id)
	ON DELETE CASCADE
	ON UPDATE RESTRICT,
CONSTRAINT `geschlecht`
	FOREIGN KEY(fk_geschlecht) REFERENCES tbl_geschlecht(pk_geschlecht)
	ON DELETE CASCADE
	ON UPDATE RESTRICT
)ENGINE = InnoDB;

DROP TABLE IF EXISTS tbl_character_type;
CREATE TABLE tbl_character_type(
pk_character_type_id INT PRIMARY KEY AUTO_INCREMENT,
name VARCHAR(32)
)ENGINE = InnoDB;

DROP TABLE IF EXISTS tbl_location;
CREATE TABLE tbl_location(
pk_location_id INT PRIMARY KEY AUTO_INCREMENT,
x INT,
y INT

)ENGINE = InnoDB;

DROP TABLE IF EXISTS tbl_equipment_slot;
CREATE TABLE tbl_equipment_slot(
pk_equipment_slot_id INT PRIMARY KEY AUTO_INCREMENT,
name VARCHAR(32)
)ENGINE = InnoDB;

DROP TABLE IF EXISTS tbl_item_type;
CREATE TABLE tbl_item_type(
pk_item_type_id INT PRIMARY KEY AUTO_INCREMENT,
name VARCHAR(32),
description VARCHAR(32)
)ENGINE = InnoDB;

DROP TABLE IF EXISTS tbl_item;
CREATE TABLE tbl_item(
pk_item_id INT PRIMARY KEY AUTO_INCREMENT,
fk_item_type_id INT,
name VARCHAR(32),
CONSTRAINT `item_type`
	FOREIGN KEY(fk_item_type_id) REFERENCES tbl_item_type(pk_item_type_id)
	ON DELETE CASCADE
	ON UPDATE RESTRICT
)ENGINE = InnoDB;

DROP TABLE IF EXISTS tbl_ability_type;
CREATE TABLE tbl_ability_type(
pk_ability_type_id INT PRIMARY KEY AUTO_INCREMENT,
name VARCHAR(32),
description VARCHAR(32)
)ENGINE = InnoDB;

DROP TABLE IF EXISTS tbl_ability;
CREATE TABLE tbl_ability(
pk_ability_id INT PRIMARY KEY AUTO_INCREMENT,
name VARCHAR(32),
fk_ability_type INT,
CONSTRAINT `ability_type`
	FOREIGN KEY(fk_ability_type) REFERENCES tbl_ability_type(pk_ability_type_id)
	ON DELETE CASCADE
	ON UPDATE RESTRICT
)ENGINE = InnoDB;

DROP TABLE IF EXISTS tbl_class;
CREATE TABLE tbl_class(
pk_class_id INT PRIMARY KEY AUTO_INCREMENT,
name VARCHAR(32)
)ENGINE = InnoDB;

DROP TABLE IF EXISTS tbl_class_ability;
CREATE TABLE tbl_class_ability(
pk_class_ability_id INT PRIMARY KEY AUTO_INCREMENT,
fk_class_id INT,
fk_ability_id INT,
CONSTRAINT `tbl_class`
	FOREIGN KEY(fk_class_id) REFERENCES tbl_class(pk_class_id)
	ON DELETE CASCADE
	ON UPDATE RESTRICT,
CONSTRAINT `ability_id_class`
	FOREIGN KEY(fk_ability_id) REFERENCES tbl_ability(pk_ability_id)
	ON DELETE CASCADE
	ON UPDATE RESTRICT
)ENGINE = InnoDB;

DROP TABLE IF EXISTS tbl_attribute;
CREATE TABLE tbl_attribute(
pk_attribute_id INT PRIMARY KEY AUTO_INCREMENT,
name VARCHAR(32),
description VARCHAR(32)
)ENGINE = InnoDB;

DROP TABLE IF EXISTS tbl_item_attribute;
CREATE TABLE tbl_item_attribute(
pk_item_attribute_id INT PRIMARY KEY AUTO_INCREMENT,
fk_item_id INT,
fk_attribute_id INT,
CONSTRAINT `item`
	FOREIGN KEY(fk_item_id) REFERENCES tbl_item(pk_item_id)
	ON DELETE CASCADE
	ON UPDATE RESTRICT,
CONSTRAINT `attribute`
	FOREIGN KEY(fk_attribute_id) REFERENCES tbl_attribute(pk_attribute_id)
	ON DELETE CASCADE
	ON UPDATE RESTRICT
)ENGINE = InnoDB;

DROP TABLE IF EXISTS tbl_character;
CREATE TABLE tbl_character(
pk_character_id INT PRIMARY KEY AUTO_INCREMENT,
fk_character_type INT,
name VARCHAR(32),
level INT,
xp double,
money double,

CONSTRAINT `character_type`
	FOREIGN KEY(fk_character_type) REFERENCES tbl_character_type(pk_character_type_id)
	ON DELETE CASCADE
	ON UPDATE RESTRICT
)ENGINE = InnoDB;

DROP TABLE IF EXISTS tbl_user_character;
CREATE TABLE tbl_user_character(
pk_user_character_id INT PRIMARY KEY AUTO_INCREMENT,
fk_user_id INT,
fk_character_id INT,
CONSTRAINT `user_id`
	FOREIGN KEY(fk_user_id) REFERENCES tbl_user(pk_user_id)
	ON DELETE CASCADE
	ON UPDATE RESTRICT,
CONSTRAINT `character_id_user`
	FOREIGN KEY(fk_character_id) REFERENCES tbl_character(pk_character_id)
	ON DELETE CASCADE
	ON UPDATE RESTRICT
)ENGINE = InnoDB;

DROP TABLE IF EXISTS tbl_character_equipment;
CREATE TABLE tbl_character_equipment(
pk_character_equipment_id INT PRIMARY KEY AUTO_INCREMENT,
fk_equipment_slot_id INT,
fk_character_id INT,
CONSTRAINT `equipment slot`
	FOREIGN KEY(fk_equipment_slot_id) REFERENCES tbl_equipment_slot(pk_equipment_slot_id)
	ON DELETE CASCADE
	ON UPDATE RESTRICT,
CONSTRAINT `charcter`
	FOREIGN KEY(fk_character_id) REFERENCES tbl_character(pk_character_id)
	ON DELETE CASCADE
	ON UPDATE RESTRICT

)ENGINE = InnoDB;

DROP TABLE IF EXISTS tbl_character_item;
CREATE TABLE tbl_character_item(
pk_character_item_id INT PRIMARY KEY AUTO_INCREMENT,
fk_character_id INT,
fk_item_id INT,
CONSTRAINT `character_id`
	FOREIGN KEY(fk_character_id) REFERENCES tbl_character(pk_character_id)
	ON DELETE CASCADE
	ON UPDATE RESTRICT,
CONSTRAINT `item_id`
	FOREIGN KEY(fk_item_id) REFERENCES tbl_item(pk_item_id)
	ON DELETE CASCADE
	ON UPDATE RESTRICT
)ENGINE = InnoDB;

DROP TABLE IF EXISTS tbl_character_location;
CREATE TABLE tbl_character_location(
pk_character_location_id INT PRIMARY KEY AUTO_INCREMENT,
fk_character_id INT,
fk_location_id INT,
CONSTRAINT `characterid`
	FOREIGN KEY(fk_character_id) REFERENCES tbl_character(pk_character_id)
	ON DELETE CASCADE
	ON UPDATE RESTRICT,
CONSTRAINT `location_id`
	FOREIGN KEY(fk_location_id) REFERENCES tbl_location(pk_location_id)
	ON DELETE CASCADE
	ON UPDATE RESTRICT
)ENGINE = InnoDB;

DROP TABLE IF EXISTS tbl_character_attribute;
CREATE TABLE tbl_character_attribute(
pk_character_attribute_id INT PRIMARY KEY AUTO_INCREMENT,
fk_character_id INT,
fk_attribute_id INT,
CONSTRAINT `character_id_attribute`
	FOREIGN KEY(fk_character_id) REFERENCES tbl_character(pk_character_id)
	ON DELETE CASCADE
	ON UPDATE RESTRICT,
CONSTRAINT `attribute_id`
	FOREIGN KEY(fk_attribute_id) REFERENCES tbl_attribute(pk_attribute_id)
	ON DELETE CASCADE
	ON UPDATE RESTRICT
)ENGINE = InnoDB;

DROP TABLE IF EXISTS tbl_character_class;
CREATE TABLE tbl_character_class(
pk_character_class_id INT PRIMARY KEY AUTO_INCREMENT,
fk_character_id INT,
fk_class_id INT,
CONSTRAINT `character_id_class`
	FOREIGN KEY(fk_character_id) REFERENCES tbl_character(pk_character_id)
	ON DELETE CASCADE
	ON UPDATE RESTRICT,
CONSTRAINT `class_id`
	FOREIGN KEY(fk_class_id) REFERENCES tbl_class(pk_class_id)
	ON DELETE CASCADE
	ON UPDATE RESTRICT
)ENGINE = InnoDB;