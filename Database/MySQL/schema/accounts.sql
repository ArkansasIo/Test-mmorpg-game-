CREATE TABLE IF NOT EXISTS accounts (
    account_id CHAR(36) NOT NULL,
    created_at TIMESTAMP NOT NULL DEFAULT CURRENT_TIMESTAMP,
    updated_at TIMESTAMP NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
    is_active BOOLEAN NOT NULL DEFAULT TRUE,
    PRIMARY KEY (account_id)
) ENGINE=InnoDB;

CREATE TABLE IF NOT EXISTS platform_identities (
    identity_id BIGINT UNSIGNED NOT NULL AUTO_INCREMENT,
    account_id CHAR(36) NOT NULL,
    platform VARCHAR(32) NOT NULL,
    platform_user_id VARCHAR(255) NOT NULL,
    display_name VARCHAR(255) NULL,
    verified_at TIMESTAMP NULL,
    created_at TIMESTAMP NOT NULL DEFAULT CURRENT_TIMESTAMP,
    PRIMARY KEY (identity_id),
    UNIQUE KEY uq_platform_identity (platform, platform_user_id),
    KEY ix_identity_account (account_id),
    CONSTRAINT fk_identity_account FOREIGN KEY (account_id)
        REFERENCES accounts(account_id) ON DELETE CASCADE
) ENGINE=InnoDB;
