CREATE TABLE IF NOT EXISTS sessions (
    session_id CHAR(36) NOT NULL,
    account_id CHAR(36) NOT NULL,
    character_id CHAR(36) NULL,
    platform VARCHAR(32) NOT NULL,
    realm_id VARCHAR(128) NOT NULL,
    issued_at TIMESTAMP NOT NULL DEFAULT CURRENT_TIMESTAMP,
    expires_at TIMESTAMP NOT NULL,
    revoked_at TIMESTAMP NULL,
    PRIMARY KEY (session_id),
    KEY ix_sessions_account (account_id),
    KEY ix_sessions_realm (realm_id)
) ENGINE=InnoDB;
