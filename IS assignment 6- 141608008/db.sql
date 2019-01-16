DROP TABLE IF EXISTS `users`;

CREATE TABLE `users` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `username` varchar(20) DEFAULT NULL,
  `password` varchar(20) DEFAULT NULL,
  `firstname` varchar(20) DEFAULT NULL,
  `surname` varchar(20) DEFAULT NULL,
  `email` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`id`)
);

LOCK TABLES `users` WRITE;
INSERT INTO `users` VALUES (1,'vaish','vai','vaish','s','vai@mail.com'),(2,'perry','perry','perry','platypus','platypus@mail.com');
UNLOCK TABLES;
