CREATE TABLE IF NOT EXISTS character_snapshots (
    snapshot_id BIGINT UNSIGNED NOT NULL AUTO_INCREMENT,
    character_id CHAR(36) NOT NULL,
    revision BIGINT UNSIGNED NOT NULL,
    schema_version INT UNSIGNED NOT NULL DEFAULT 1,
    source_platform VARCHAR(32) NOT NULL,
    payload_hash CHAR(64) NOT NULL,
    payload JSON NOT NULL,
    created_at TIMESTAMP NOT NULL DEFAULT CURRENT_TIMESTAMP,
    PRIMARY KEY (snapshot_id),
    UNIQUE KEY uq_character_revision (character_id, revision),
    KEY ix_character_latest (character_id, created_at)
) ENGINE=InnoDB;
