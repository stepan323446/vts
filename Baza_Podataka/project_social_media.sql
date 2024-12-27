-- +------------------------------+
-- |          U S E R S           |
-- +------------------------------+
CREATE TABLE users (
    -- Private information
    id              INT IDENTITY UNIQUE NOT NULL,
    username        VARCHAR UNIQUE NOT NULL,
    password        VARCHAR NOT NULL,
    email           VARCHAR UNIQUE NOT NULL,
    role            CHAR(15) NOT NULL DEFAULT 'user',
    is_active       INT NOT NULL DEFAULT 1,

    last_login      DATETIME NULL,
    data_joined     DATETIME DEFAULT CURRENT_TIMESTAMP,

    -- Public information
    first_name      VARCHAR DEFAULT '',
    last_name       VARCHAR DEFAULT '',
    avatar_url      VARCHAR NULL,
    display_name    VARCHAR NULL,
    publicity       CHAR(30) NOT NULL DEFAULT 'everyone',

    CONSTRAINT user_pk PRIMARY KEY(id),
    CONSTRAINT user_role_check CHECK(role IN ('blocked', 'user', 'admin')),
    CONSTRAINT user_publicity_check CHECK(publicity IN ('private', 'only_friends', 'friend_friends', 'everyone'))
);
CREATE TABLE notifications (
    id              INT IDENTITY UNIQUE NOT NULL,
    name            VARCHAR NOT NULL,
    content         VARCHAR NULL,
    
    created_at      DATETIME DEFAULT CURRENT_TIMESTAMP,
    
    user_id         INT NOT NULL,

    CONSTRAINT notification_pk PRIMARY KEY(id),

    FOREIGN KEY(user_id) REFERENCES users(id)
);

-- Blacklisted users cannot add others as subscribers.
CREATE TABLE blacklist (
    user_id         INT NOT NULL,
    blocked_user_id INT NOT NULL,

    created_at      DATETIME DEFAULT CURRENT_TIMESTAMP,

    FOREIGN KEY(user_id) REFERENCES users(id),
    FOREIGN KEY(blocked_user_id) REFERENCES users(id)
);

-- if users are subscribed to each other, they are friends.
CREATE TABLE followers (
    follower_user_id        INT NOT NULL,
    followed_user_id		INT NOT NULL,

    created_at      DATETIME DEFAULT CURRENT_TIMESTAMP,

    FOREIGN KEY(follower_user_id) REFERENCES users(id),
    FOREIGN KEY(followed_user_id) REFERENCES users(id)
);


-- +------------------------------+
-- |          C H A T S           |
-- +------------------------------+
CREATE TABLE chats (
    id              INT IDENTITY UNIQUE NOT NULL,
    name            VARCHAR NOT NULL,
    type            CHAR(15) NOT NULL DEFAULT 'personal',
    is_closed       INT NOT NULL DEFAULT 0,

    created_at      DATETIME DEFAULT CURRENT_TIMESTAMP,
    updated_at      DATETIME DEFAULT CURRENT_TIMESTAMP,

    CONSTRAINT chat_pk PRIMARY KEY(id),
    CONSTRAINT chat_type_check CHECK(type IN ('personal', 'group'))
);
CREATE TABLE chat_participants (
    is_admin        INT NOT NULL DEFAULT 0,

    user_id         INT NOT NULL,
    chat_id         INT NOT NULL,

    FOREIGN KEY(user_id) REFERENCES users(id),
    FOREIGN KEY(chat_id) REFERENCES chats(id)
);
CREATE TABLE chat_messages (
    id              INT IDENTITY UNIQUE NOT NULL,
    content         TEXT NOT NULL,

    user_id         INT NOT NULL,
    chat_id         INT NOT NULL,

	CONSTRAINT chat_message_pk PRIMARY KEY(id),

    FOREIGN KEY(user_id) REFERENCES users(id),
    FOREIGN KEY(chat_id) REFERENCES chats(id)
);

-- +------------------------------+
-- |          P O S T S           |
-- +------------------------------+
CREATE TABLE posts (
    id              INT IDENTITY UNIQUE NOT NULL,
    content         TEXT NOT NULL,

    user_id         INT NOT NULL,

    created_at      DATETIME DEFAULT CURRENT_TIMESTAMP,
    updated_at      DATETIME DEFAULT CURRENT_TIMESTAMP,

    CONSTRAINT post_pk PRIMARY KEY(id),
    
    FOREIGN KEY(user_id) REFERENCES users(id)
);
CREATE TABLE post_comments (
    id              INT IDENTITY UNIQUE NOT NULL,
    content         TEXT NOT NULL,

    created_at      DATETIME DEFAULT CURRENT_TIMESTAMP,
    updated_at      DATETIME DEFAULT CURRENT_TIMESTAMP,

    -- If user reply other comment
    parent_id        INT NULL,

    post_id         INT NOT NULL,
    user_id         INT NOT NULL,

    CONSTRAINT post_comment_pk PRIMARY KEY(id),

    FOREIGN KEY(parent_id) REFERENCES post_comments(id),
    FOREIGN KEY(post_id) REFERENCES posts(id),
    FOREIGN KEY(user_id) REFERENCES users(id)
);
CREATE TABLE post_reactions (
    id              INT IDENTITY UNIQUE NOT NULL,
    type            CHAR(15) NOT NULL DEFAULT 'like',

    created_at      DATETIME DEFAULT CURRENT_TIMESTAMP,

    post_id         INT NOT NULL,
    user_id         INT NOT NULL,
    
    CONSTRAINT post_reaction_pk PRIMARY KEY(id),
    CONSTRAINT post_reaction_type CHECK(type IN ('like', 'dislike')),

    FOREIGN KEY(post_id) REFERENCES posts(id),
    FOREIGN KEY(user_id) REFERENCES users(id)
);

-- +------------------------------+
-- |          F I L E S           |
-- +------------------------------+

-- Only for images
CREATE TABLE albums (
    id              INT IDENTITY UNIQUE NOT NULL,
    description     VARCHAR NULL,
    is_private      INT NOT NULL DEFAULT 0,

    created_at      DATETIME DEFAULT CURRENT_TIMESTAMP,
    updated_at      DATETIME DEFAULT CURRENT_TIMESTAMP,

    user_id         INT NOT NULL,

    CONSTRAINT album_pk PRIMARY KEY(id),

    FOREIGN KEY(user_id) REFERENCES users(id)
);
CREATE TABLE files (
    id              INT IDENTITY UNIQUE NOT NULL,
    path_url        VARCHAR NOT NULL,
    description     VARCHAR NULL,
    type            CHAR(15) NOT NULL,

    created_at      DATETIME DEFAULT CURRENT_TIMESTAMP,
    updated_at      DATETIME DEFAULT CURRENT_TIMESTAMP,

    album_id        INT NULL,
    user_id         INT NOT NULL,

    CONSTRAINT file_pk PRIMARY KEY(id),
    CONSTRAINT file_type_check CHECK(type IN ('file', 'image', 'audio', 'video')),

    FOREIGN KEY(album_id) REFERENCES albums(id),
    FOREIGN KEY(user_id) REFERENCES users(id)
);

-- Pinned files to post, to messages
CREATE TABLE message_pinned_files (
    message_id      INT NOT NULL,
    file_id         INT NOT NULL,
    sort_order      INT NOT NULL DEFAULT 0,

    FOREIGN KEY(message_id) REFERENCES chat_messages(id),
    FOREIGN KEY(file_id) REFERENCES files(id)
);
CREATE TABLE post_pinned_files (
    post_id         INT NOT NULL,
    file_id         INT NOT NULL,
    sort_order      INT NOT NULL DEFAULT 0,

    FOREIGN KEY(post_id) REFERENCES post_comments(id),
    FOREIGN KEY(file_id) REFERENCES files(id)
);
