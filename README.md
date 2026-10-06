## To Start

Run `openskydimo help` to start.

## Ubuntu

### Install

Add the repository and key manually.

```bash
curl -fsSL https://chanuka-williams.github.io/openskydimo-apt/openskydimo-archive-keyring.gpg.asc | \
sudo tee /usr/share/keyrings/openskydimo-archive-keyring.asc > /dev/null

echo "deb [signed-by=/usr/share/keyrings/openskydimo-archive-keyring.asc] \
https://chanuka-williams.github.io/openskydimo-apt stable main" | \
sudo tee /etc/apt/sources.list.d/openskydimo.list

sudo apt update
sudo apt install openskydimo
```

## Arch Linux

### Install

```bash
yay -S openskydimo   # or your preferred AUR helper
```

After installing, enable and start the service:

```bash
sudo systemctl enable --now openskydimo
```

## Multiple users

The daemon is a single system-wide service (there is only one physical set of lights), so it works no matter how many
users are logged in. All users talk to it through `/run/openskydimo/openskydimo.sock`, and its settings live in
`/var/lib/openskydimo/config.json`.

If you previously used the per-user service, stop it with `systemctl --user disable --now openskydimo` and re-run
`openskydimo set port ...` / `set count ...` once, since the old config was stored under `~/.config/openskydimo`.

For development, you can run the daemon unprivileged with
`OPENSKYDIMO_SOCKET=/tmp/osd.sock OPENSKYDIMO_CONFIG=/tmp/osd.json openskydimo-daemon` and use the same
`OPENSKYDIMO_SOCKET` for the CLI.
