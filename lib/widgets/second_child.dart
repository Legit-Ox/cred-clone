import 'package:cred/utils/size_config.dart';
import 'package:flutter/material.dart';

class SecondChild extends StatefulWidget {
  const SecondChild({required this.closeSecondChild, super.key});
  final VoidCallback closeSecondChild;

  @override
  State<SecondChild> createState() => _SecondChildState();
}

class _SecondChildState extends State<SecondChild> {
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      body: SizedBox(
        height: SizeConfig().screenHeight * 0.5,
        child: Column(
          mainAxisAlignment: MainAxisAlignment.center,
          crossAxisAlignment: CrossAxisAlignment.center,
          children: [
            ElevatedButton(
                onPressed: widget.closeSecondChild,
                child: const Text('Close second child')),
          ],
        ),
      ),
    );
  }
}
