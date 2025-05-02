-- MySQL dump 10.13  Distrib 8.0.41, for Win64 (x86_64)
--
-- Host: localhost    Database: pharmacy_db
-- ------------------------------------------------------
-- Server version	8.0.41

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!50503 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `expenses`
--

DROP TABLE IF EXISTS `expenses`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `expenses` (
  `id` int NOT NULL AUTO_INCREMENT,
  `description` varchar(255) DEFAULT NULL,
  `amount` decimal(10,2) DEFAULT NULL,
  `date` date DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=14 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `expenses`
--

LOCK TABLES `expenses` WRITE;
/*!40000 ALTER TABLE `expenses` DISABLE KEYS */;
INSERT INTO `expenses` VALUES 
(1,'Monthly Rent for Pharmacy',1500.00,'2025-04-01'),
(2,'Electricity Bill',320.50,'2025-04-03'),
(3,'Water and Sanitation',145.75,'2025-04-03'),
(4,'Staff Salaries',4500.00,'2025-04-05'),
(5,'Purchase of New Medicine Stock',2800.00,'2025-04-06'),
(6,'Internet and Phone Bill',110.00,'2025-04-07'),
(7,'Cleaning Supplies',75.30,'2025-04-08'),
(8,'Pharmacy Software License Renewal',250.00,'2025-04-09'),
(9,'Refrigerator Maintenance',180.00,'2025-04-10'),
(10,'Transportation Cost (Medicine Delivery)',225.00,'2025-04-11'),
(11,'Staff Uniforms',200.00,'2025-04-12'),
(12,'Insurance Payment',600.00,'2025-04-13'),
(13,'Miscellaneous Expenses',95.00,'2025-04-14');
/*!40000 ALTER TABLE `expenses` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `medicines`
--

DROP TABLE IF EXISTS `medicines`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `medicines` (
  `id` int NOT NULL AUTO_INCREMENT,
  `name` varchar(100) NOT NULL,
  `price` decimal(10,2) NOT NULL,
  `expiry_date` date DEFAULT NULL,
  `category` varchar(50) DEFAULT NULL,
  `quantity` int DEFAULT '0',
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=27 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `medicines`
--

LOCK TABLES `medicines` WRITE;
/*!40000 ALTER TABLE `medicines` DISABLE KEYS */;
INSERT INTO `medicines` VALUES 
(1,'Paracetamol',2.50,'2026-12-31','Analgesic',100),
(2,'Amoxicillin',5.00,'2027-06-30','Antibiotic',150),
(3,'Ciprofloxacin',7.00,'2026-09-15','Antibiotic',120),
(4,'Metformin',6.50,'2027-03-20','Antidiabetic',80),
(5,'Salbutamol',8.00,'2026-11-10','Bronchodilator',90),
(6,'Atenolol',4.00,'2027-05-25','Antihypertensive',110),
(7,'Omeprazole',3.50,'2027-02-28','Proton Pump Inhibitor',130),
(8,'Ibuprofen',2.80,'2026-08-05','NSAID',140),
(9,'Diazepam',5.20,'2026-12-15','Anxiolytic',70),
(10,'Captopril',3.00,'2027-04-10','Antihypertensive',100),
(11,'Simvastatin',6.00,'2027-07-30','Antihyperlipidemic',85),
(12,'Diclofenac',3.80,'2026-10-20','NSAID',95),
(13,'Co-trimoxazole',4.50,'2026-09-05','Antibiotic',110),
(14,'Loperamide',1.50,'2026-07-15','Antidiarrheal',150),
(15,'Metoclopramide',2.20,'2026-11-25','Antiemetic',120),
(16,'Bisoprolol',5.60,'2027-01-30','Antihypertensive',90),
(17,'Glibenclamide',4.80,'2027-03-10','Antidiabetic',100),
(18,'Omeprazole',3.50,'2027-02-28','Proton Pump Inhibitor',130),
(19,'Hydrocortisone',6.00,'2026-12-05','Corticosteroid',75),
(20,'Furosemide',2.90,'2026-08-10','Diuretic',140),
(21,'Azithromycin',7.50,'2026-09-25','Antibiotic',100),
(22,'Albendazole',3.00,'2027-05-15','Anthelmintic',130),
(23,'Doxycycline',5.50,'2026-10-30','Antibiotic',85),
(24,'Fluoxetine',6.20,'2027-04-05','Antidepressant',90),
(25,'Risperidone',7.00,'2026-12-20','Antipsychotic',80),
(26,'Haloperidol',4.50,'2027-01-15','Antipsychotic',100);
/*!40000 ALTER TABLE `medicines` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `sales`
--

DROP TABLE IF EXISTS `sales`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `sales` (
  `id` int NOT NULL AUTO_INCREMENT,
  `medicine_id` int DEFAULT NULL,
  `quantity` int DEFAULT NULL,
  `total_price` decimal(10,2) DEFAULT NULL,
  `sale_date` datetime DEFAULT CURRENT_TIMESTAMP,
  PRIMARY KEY (`id`),
  KEY `medicine_id` (`medicine_id`),
  CONSTRAINT `sales_ibfk_1` FOREIGN KEY (`medicine_id`) REFERENCES `medicines` (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `sales`
--

LOCK TABLES `sales` WRITE;
/*!40000 ALTER TABLE `sales` DISABLE KEYS */;
/*!40000 ALTER TABLE `sales` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2025-05-02 12:03:29
