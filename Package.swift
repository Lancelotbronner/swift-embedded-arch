// swift-tools-version: 6.4
// The swift-tools-version declares the minimum version of Swift required to build this package.

import PackageDescription

let package = Package(
	name: "swift-embedded-arch",
	products: [
		.library(name: "EmbeddedArch", targets: ["EmbeddedArch"]),
	],
	dependencies: [
		.package(url: "https://github.com/swiftlang/swift-docc-plugin", from: "1.5.0"),
	],
	targets: [
		.target(name: "EmbeddedArch"),
	],
	cLanguageStandard: .c2x
)
