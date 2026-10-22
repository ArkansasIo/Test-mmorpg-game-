CREATE TABLE IF NOT EXISTS characters (
    character_id CHAR(36) NOT NULL,
    account_id CHAR(36) NOT NULL,
    character_name VARCHAR(64) NOT NULL,
    level INT NOT NULL DEFAULT 1,
    experience BIGINT NOT NULL DEFAULT 0,
    zone_id VARCHAR(64) NOT NULL DEFAULT 'GreenwardFrontier',
    created_at TIMESTAMP NOT NULL DEFAULT CURRENT_TIMESTAMP,
    updated_at TIMESTAMP NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
    PRIMARY KEY (character_id),
    UNIQUE KEY uq_characters_account_name (account_id, character_name),
    KEY idx_characters_account (account_id),
    CONSTRAINT fk_characters_account FOREIGN KEY (account_id) REFERENCES accounts(account_id)
);

CREATE TABLE IF NOT EXISTS character_save_revisions (
    character_id CHAR(36) NOT NULL,
    revision BIGINT NOT NULL,
    schema_version INT NOT NULL DEFAULT 1,
    source_platform VARCHAR(32) NOT NULL,
    payload_hash CHAR(64) NOT NULL,
    payload_json JSON NOT NULL,
    created_at TIMESTAMP NOT NULL DEFAULT CURRENT_TIMESTAMP,
    PRIMARY KEY (character_id, revision),
    KEY idx_save_revision_hash (payload_hash),
    CONSTRAINT fk_save_revision_character FOREIGN KEY (character_id) REFERENCES characters(character_id)
);
