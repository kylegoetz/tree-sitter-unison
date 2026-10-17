{
  inputs.nixpkgs.url = "https://channels.nixos.org/nixpkgs-unstable/nixexprs.tar.zst";

  outputs = { nixpkgs, ... }:
    let
      systems = ["x86_64-linux" "aarch64-linux" "aarch64-darwin"];
      forEachSystem = f: nixpkgs.lib.genAttrs systems (system: f nixpkgs.legacyPackages.${system});
    in
    {
      devShells = forEachSystem (pkgs: {
        default = pkgs.mkShell {
          name = "tree-sitter-unison";
          packages = [
            pkgs.nodejs
            pkgs.python3
            (pkgs.tree-sitter.overrideAttrs (let
              src = pkgs.fetchFromGitHub {
                owner = "tree-sitter";
                repo = "tree-sitter";
                tag = "v0.27.1";
                hash = "sha256-KbPqA6pfplWRUtwRgbNXUF7aivj/n4shJqWbjNO93nQ=";
              };
            in {
              version = "0.27.1";
              inherit src;
              cargoDeps = pkgs.rustPlatform.fetchCargoVendor {
                inherit src;
                hash = "sha256-GbW/qFq8X0UNi9LIepTIAKSAqCXM/gdy6XV6s5YO8r0=";
              };
              patches = [];
            }))
          ];
        };
      });
    };
}
