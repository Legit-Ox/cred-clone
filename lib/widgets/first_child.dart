import 'package:cred/utils/size_config.dart';
import 'package:flutter/material.dart';

class FirstChild extends StatefulWidget {
  const FirstChild(
      {required this.closeFirstChild,
      required this.openSecondChild,
      super.key});
  final VoidCallback openSecondChild;
  final VoidCallback closeFirstChild;

  @override
  State<FirstChild> createState() => _FirstChildState();
}

class _FirstChildState extends State<FirstChild> {
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      body: SizedBox(
        height: SizeConfig().screenHeight * 0.7,
        child: Column(
          mainAxisAlignment: MainAxisAlignment.center,
          crossAxisAlignment: CrossAxisAlignment.center,
          children: [
            ElevatedButton(
                onPressed: () {
                  widget.openSecondChild();
                },
                child: const Text('Go to second child')),
            ElevatedButton(
                onPressed: () {
                  widget.closeFirstChild();
                },
                child: const Text('Close First child')),
          ],
        ),
      ),
    );
  }
}
