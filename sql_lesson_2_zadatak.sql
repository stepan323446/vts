-- Remove tables
IF OBJECT_ID('dbo.order_items', 'U') IS NOT NULL
	DROP TABLE order_items;

IF OBJECT_ID('dbo.card_item', 'U') IS NOT NULL
	DROP TABLE card_item;

IF OBJECT_ID('dbo.product', 'U') IS NOT NULL
	DROP TABLE product;

IF OBJECT_ID('dbo.discount', 'U') IS NOT NULL
	DROP TABLE discount;

IF OBJECT_ID('dbo.payment_details', 'U') IS NOT NULL
	DROP TABLE payment_details;

IF OBJECT_ID('dbo.order_detail', 'U') IS NOT NULL
	DROP TABLE order_detail;

IF OBJECT_ID('dbo.shopping_session', 'U') IS NOT NULL
	DROP TABLE shopping_session;

IF OBJECT_ID('dbo.site_user', 'U') IS NOT NULL
	DROP TABLE site_user;
	

CREATE TABLE site_user(
	id			INT NOT NULL,
	username	VARCHAR NOT NULL,
	password	TEXT,
	first_name	DECIMAL NOT NULL,
	last_name	DECIMaL NOT NULL,
	address		VARCHAR(150) NOT NULL,
	telephone	INT,
	created_at	DATETIME DEFAULT CURRENT_TIMESTAMP NOT NULL,
	modified_at	DATETIME DEFAULT CURRENT_TIMESTAMP NOT NULL,

	CONSTRAINT user_pk PRIMARY KEY(id),
);
GO
CREATE TABLE shopping_session(
	id			INT NOT NULL,
	user_id		INT NOT NULL,
	total		DECIMAL DEFAULT '0' NOT NULL,
	created_at	DATETIME DEFAULT CURRENT_TIMESTAMP NOT NULL,
	modified_at	DATETIME DEFAULT CURRENT_TIMESTAMP NOT NULL,

	CONSTRAINT shopping_session_pk PRIMARY KEY(id),
	FOREIGN KEY(user_id) REFERENCES site_user(id)
);
GO

CREATE TABLE order_detail(
	id			INT NOT NULL,
	user_id		INT NOT NULL,
	total		DECIMAL NOT NULL,
	payment_id	INT NOT NULL,
	created_at	DATETIME DEFAULT CURRENT_TIMESTAMP NOT NULL,
	modified_at	DATETIME DEFAULT CURRENT_TIMESTAMP NOT NULL,

	CONSTRAINT order_detail_pk PRIMARY KEY(id),
	FOREIGN KEY(user_id) REFERENCES site_user(id)
);
GO

CREATE TABLE discount(
	id			INT NOT NULL,
	name		VARCHAR(150) NOT NULL,
	descpr		TEXT NOT NULL,
	discount_percent DECIMAL,
	created_at	DATETIME DEFAULT CURRENT_TIMESTAMP NOT NULL,
	modified_at	DATETIME DEFAULT CURRENT_TIMESTAMP NOT NULL,

	CONSTRAINT discount_pk PRIMARY KEY(id),
);

CREATE TABLE product(
	id			INT NOT NULL,
	name		VARCHAR(150) NOT NULL,
	descpr		TEXT NOT NULL,
	SKU			VARCHAR(150) NOT NULL,
	category	VARCHAR(150) NOT NULL,
	price		DECIMAL DEFAULT '0' NOT NULL,
	discount_id	INT NULL,
	created_at	DATETIME DEFAULT CURRENT_TIMESTAMP NOT NULL,
	modified_at	DATETIME DEFAULT CURRENT_TIMESTAMP NOT NULL,

	CONSTRAINT product_pk PRIMARY KEY(id),
	FOREIGN KEY(discount_id) REFERENCES discount(id)
);
GO

CREATE TABLE card_item(
	id			INT NOT NULL,
	session_id	INT NOT NULL,
	product_id	INT NOT NULL,
	quantity	INT DEFAULT '1' NOT NULL,
	created_at	DATETIME DEFAULT CURRENT_TIMESTAMP NOT NULL,
	modified_at	DATETIME DEFAULT CURRENT_TIMESTAMP NOT NULL,

	CONSTRAINT card_item_pk PRIMARY KEY(id),
	FOREIGN KEY(session_id) REFERENCES shopping_session(id),
	FOREIGN KEY(product_id) REFERENCES product(id),
);
GO

CREATE TABLE order_items(
	id			INT NOT NULL,
	order_id	INT NOT NULL,
	product_id	INT NOT NULL,
	created_at	DATETIME DEFAULT CURRENT_TIMESTAMP NOT NULL,
	modified_at	DATETIME DEFAULT CURRENT_TIMESTAMP NOT NULL,

	CONSTRAINT order_items_pk PRIMARY KEY(id),
	FOREIGN KEY(order_id) REFERENCES order_detail(id),
	FOREIGN KEY(product_id) REFERENCES product(id)
);
GO

CREATE TABLE payment_details(
	id			INT NOT NULL,
	order_id	INT NOT NULL,
	amount		INT default '1' NOT NULL,
	provider	VARCHAR(150) NOT NULL,
	status		VARCHAR(150) NOT NULL,
	created_at	DATETIME DEFAULT CURRENT_TIMESTAMP  NOT NULL,
	modified_at	DATETIME DEFAULT CURRENT_TIMESTAMP NOT NULL,

	CONSTRAINT payment_pk PRIMARY KEY(id),
	CONSTRAINT payment_status CHECK(status IN ('completed', 'processing', 'cancelled')),
	FOREIGN KEY(order_id) REFERENCES order_detail(id)
);

