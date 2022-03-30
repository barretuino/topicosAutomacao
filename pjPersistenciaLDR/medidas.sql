CREATE TABLE `pjgerencia`.`medidas` (
  `data` DATE NOT NULL,
  `hora` TIME NOT NULL,
  `valor` FLOAT NOT NULL,
  PRIMARY KEY (`data`)
)
ENGINE = InnoDB;