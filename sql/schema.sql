-- Create the database
CREATE DATABASE IF NOT EXISTS fop_db2;
USE fop_db2;

-- Table: Category
CREATE TABLE IF NOT EXISTS Category (
    id INT AUTO_INCREMENT PRIMARY KEY,
    category_name VARCHAR(255) UNIQUE,
    description VARCHAR(255)
);

-- Table: Drug
CREATE TABLE IF NOT EXISTS Drug (
    id INT AUTO_INCREMENT PRIMARY KEY,
    name VARCHAR(255) NOT NULL,
    quantity_stock INT,
    price_purchase DECIMAL(10, 2),
    price_selling DECIMAL(10, 2),
    expiration_date DATE,
    insertion_date TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    description VARCHAR(255),
    category_id INT,
    FOREIGN KEY (category_id) REFERENCES Category(id) ON DELETE SET NULL
);



-- Table: Sales
CREATE TABLE IF NOT EXISTS Sales (
    sale_id INT AUTO_INCREMENT PRIMARY KEY,
    drug_id INT,
    quantity_sold INT,
    total_price DECIMAL(10, 2),
    sale_date TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    FOREIGN KEY (drug_id) REFERENCES Drug(id) ON DELETE CASCADE
);

-- Table: Expired_Drug_Log
CREATE TABLE IF NOT EXISTS Expired_Drug_Log (
    log_id INT AUTO_INCREMENT PRIMARY KEY,
    drug_id INT,
    expiry_date DATE,
    notification_date DATETIME,
    FOREIGN KEY (drug_id) REFERENCES Drug(id) ON DELETE CASCADE
);

-- Table: Transaction_Log
CREATE TABLE IF NOT EXISTS Transaction_Log (
    transaction_id INT AUTO_INCREMENT PRIMARY KEY,
    type ENUM('Sale', 'Expense'),
    amount DECIMAL(10, 2),
    transaction_date TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    description VARCHAR(255)
);

-- Category
INSERT IGNORE INTO Category (id, category_name, description) VALUES
(1, 'Antibiotics', 'Used to treat bacterial infections'),
(2, 'Pain Relievers', 'Used to reduce pain'),
(3, 'Vitamins', 'Used to supplement diet');

-- Drug
INSERT IGNORE INTO Drug (id, name, quantity_stock, price_purchase, price_selling, expiration_date, insertion_date, description) VALUES
(1, 'Amoxicillin 500mg', 100, 3.50, 5.00, '2025-12-15', NOW(), 'Common antibiotic for infections'),
(2, 'Paracetamol 500mg', 200, 0.10, 0.25, '2026-03-01', NOW(), 'Pain and fever reducer'),
(3, 'Vitamin C 1000mg', 150, 0.50, 1.00, '2025-11-10', NOW(), 'Boosts immunity');

-- Drug_Categories
INSERT IGNORE INTO Drug_Categories (drug_id, category_id) VALUES
(1, 1),
(2, 2),
(3, 3);

-- Sales
INSERT IGNORE INTO Sales (sale_id, drug_id, quantity_sold, total_price, sale_date) VALUES
(1, 1, 10, 50.00, NOW() - INTERVAL 1 DAY),
(2, 2, 20, 5.00, NOW()),
(3, 3, 15, 15.00, NOW() - INTERVAL 2 DAY);

-- Expired_Drug_Log
INSERT IGNORE INTO Expired_Drug_Log (log_id, drug_id, expiry_date, notification_date) VALUES
(1, 1, '2025-12-15', NOW() - INTERVAL 5 DAY),
(2, 3, '2025-11-10', NOW() - INTERVAL 3 DAY),
(3, 2, '2023-12-31', NOW() - INTERVAL 30 DAY);

-- Transaction_Log
INSERT IGNORE INTO Transaction_Log (transaction_id, type, amount, transaction_date, description) VALUES
(1, 'Sale', 50.00, NOW() - INTERVAL 1 DAY, 'Sold Amoxicillin'),
(2, 'Sale', 5.00, NOW(), 'Sold Paracetamol'),
(3, 'Expense', 200.00, NOW() - INTERVAL 3 DAY, 'Stock Purchase');

